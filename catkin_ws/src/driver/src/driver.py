#!/usr/bin/env python
# license removed for brevity
import rospy
from math import *
from geometry_msgs.msg import Twist
from sensor_msgs.msg import PointCloud
from nav_msgs.msg import Odometry

sub_pose = None
sub_sonar = None
pub = None
rate = None
x = 0
y = 0
positionPoints = []
alpha = None
length = None

MAX_DISTANCE_RIGHT = -0.5

def init():
    global pub, sub_pose, sub_sonar, rate
    rospy.init_node('driver')
    pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=1)
    # MULTIPLE SUBSCRIBERS IN ONE FILE FOR SAKE OF EASE
    sub_sonar = rospy.Subscriber('/RosAria/sonar', PointCloud, drive)
    sub_pose = rospy.Subscriber('/RosAria/pose', Odometry, updatePose)
    rate = rospy.Rate(100) # 100hz

def drive(msg):
    global MAX_DISTANCE_RIGHT, alpha, length
    cmd_msg = Twist()
    cmd_msg.linear.x = 0
    cmd_msg.linear.y = 0
    cmd_msg.angular.z = 0

    R1 = magnitude(msg.points[2])
    R2 = magnitude(msg.points[3])

    length = float(msg.points[2].x + msg.points[3].x)/2
    alpha = atan(length/0.5)
    # TURN CASE
    if R2 <= 0.5/(cos(alpha-0.21)):
        cmd_msg.linear.x = 0
        cmd_msg.angular.z = (pi/2 - alpha)/2

        for i in range(2):
            pub.publish(cmd_msg)
            rospy.sleep(0.1)

        cmd_msg.angular.z = 0
        positionPoints.append((x,y))
    else:
        cmd_msg.linear.x = 0.2

    pub.publish(cmd_msg)
    rate.sleep()

def magnitude(geo_msg):
    return sqrt(geo_msg.x**2 + geo_msg.y**2)

def updatePose(msg):
    global x,y, positionPoints
    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y

def writeListToFile(list ,filename):
    f = open(filename,'w')
    stringOfCoordinates = ""
    for coordinate in list:
        for component in coordinate:
            stringOfCoordinates += str(component) + " "
        stringOfCoordinates += "\n"
    print(stringOfCoordinates)
    f.write(stringOfCoordinates)

if __name__ == '__main__':
    try:
        init()
        positionPoints.append((x,y))
        rospy.spin()
    except KeyboardInterrupt:
        print("stopped!")
    finally:
        #REPLACE WITH YOUR OWN DIRECTORY
        writeListToFile(positionPoints, "/home/jacky/catkin_ws/src/test/src/data.txt")

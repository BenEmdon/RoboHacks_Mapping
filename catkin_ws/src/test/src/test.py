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

#MAX_DISTANCE_FRONT = float(0.511)
MAX_DISTANCE_RIGHT = -0.5

def init():
    global pub, sub_pose, sub_sonar, rate
    rospy.init_node('test')
    pub = rospy.Publisher('/RosAria/cmd_vel', Twist, queue_size=1)
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

    if True: #R1 >= R2 :
        length = float(msg.points[2].x + msg.points[3].x)/2
        alpha = atan(length/0.5)
        # TURN CASE 2
        if R2 <= 0.5/(cos(alpha-0.21)):
            cmd_msg.linear.x = 0
            cmd_msg.angular.z = (pi/2 - alpha)/2

            for i in range(2):
                pub.publish(cmd_msg)
                rospy.sleep(0.1)

            cmd_msg.angular.z = 0
            positionPoints.append((x,y))
            #print(positionPoints)
        else:
            cmd_msg.linear.x = 0.2
    # TURN CASE 1
    else:
        length = float(msg.points[2].x + msg.points[3].x)/2
        alpha = acos(0.5/length)
        if R1 <= 0.5:#0.5/(cos(alpha-0.21)):
            cmd_msg.linear.x = 0
            cmd_msg.angular.z = (alpha)/2

            for i in range(2):
                pub.publish(cmd_msg)
                rospy.sleep(0.1)

            cmd_msg.angular.z = 0
            positionPoints.append((x,y))
            #print(positionPoints)

        else:
            cmd_msg.linear.x = 0.2

    #print(positionPoints)
    pub.publish(cmd_msg)
    rate.sleep()

    """
    else:
        length = -length
        if R1 <= 0.4/(cos(alpha-0.21)):
            cmd_msg.linear.x = 0
            cmd_msg.angular.z = pi/2 - alpha

            for i in range(1):
                pub.publish(cmd_msg)
                rospy.sleep(0.1)

            cmd_msg.angular.z = 0

        else:
            cmd_msg.linear.x = 0.2

    else:
        cmd_msg.linear.x = 0
        cmd_msg.angular.z = -pi/2

        for i in range(1):
            pub.publish(cmd_msg)
            rospy.sleep(0.1)

        cmd_msg.angular.z = 0
        pub.publish(cmd_msg)

        if R1 > R2:
            if R2 <= 0.4/(cos(alpha-0.21)):
                cmd_msg.linear.x = 0
                cmd_msg.angular.z = pi/2 - alpha

                for i in range(1):
                    pub.publish(cmd_msg)
                    rospy.sleep(0.1)

                cmd_msg.angular.z = 0

            else:
                cmd_msg.linear.x = 0.2
        else:
            length = -length
            if R1 <= 0.4/(cos(alpha-0.21)):
                cmd_msg.linear.x = 0
                cmd_msg.angular.z = pi/2 - alpha

                for i in range(1):
                    pub.publish(cmd_msg)
                    rospy.sleep(0.1)

                cmd_msg.angular.z = 0

            else:
                cmd_msg.linear.x = 0.2


#######################################
    # CASE 1 NO WALL IN FRONT
    if MAX_DISTANCE_FRONT < (magnitude(msg.points[2]) + magnitude(msg.points[3]))/2:

        cmd_msg.linear.x = 0.2

    else:
        cmd_msg.linear.x = 0
        cmd_msg.angular.z = 3.14/2

        for i in range(1):
            pub.publish(cmd_msg)
            rospy.sleep(0.1)

        cmd_msg.angular.z = 0
        # CASE 1.1 WALL TO THE RIGHT
        #if  msg.points[5].y < MAX_DISTANCE_RIGHT:
            # Go straight
        #cmd_msg.linear.x = 0.2
        # CASE 1.2 NO WALL TO THE RIGHT

        else:
            # Back up, turn a bit to the right
            print("CASE 1.2, NO WALL ON THE RIGHT")
            cmd_msg.linear.x = 0
            cmd_msg.angular.z = -0.5


    # CASE 2 WALL IN FRONT
    else:
        # Stop & turn left
        print("CASE 2, WALL IN FRONT")
        cmd_msg.linear.x = 0
        cmd_msg.angular.z = 0.5
#######################################
        """

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
        #print("finally?")
        writeListToFile(positionPoints, "/home/jacky/catkin_ws/src/test/src/data.txt")

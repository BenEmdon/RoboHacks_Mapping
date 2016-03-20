## Inspiration
We thought about all the cool things we could have made and this was a project the whole team could get behind. As a team comprised mostly of engineers, the design process is something we know well. Making this lengthy process automated would increase precision and reduce costs of this repetitive analysis.

## What it does
The robot goes around the flat room by the walls, turning at each corner or junction, and recording data points in an x-y plane to send back to a computer to be mapped out on a computer.

## How we built it
Using the amino bot we programmed the hardware-heavy machine to use sonar technologies to determine the length it is away from a wall. The bot is powered by ROS (Robot Operating System) and is controlled by a Linux virtual machine running custom python scripts. The data is sent back from the robot via a wireless network and the data is analyzed and graphed (using SDL). 

## Challenges we ran into
Initially, we were very limited with our hardware and were switching ideas constantly, but eventually (after 4 hours of brainstorming and circuit building) decide to go with the amigo bot as it presented a big challenge to set up but a greater reward as it's built very well. Setting up ROS with the robot was very difficult just getting the bot to move felt like a huge triumph. We attempted to get all the separate services to work together but it was exceedingly difficult because of the Linux-OS X environmental differences.

## Accomplishments that we're proud of
Getting the ROS and SDL to work! 

## What we learned
Lots of ROS and SDL.

## What's next for RobotMapper
Mapping pathways with 360-degree cameras to get information for google earth!
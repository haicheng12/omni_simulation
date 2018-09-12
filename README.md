# omni_simulation
The three omni_wheel robot simulated in gazebo.

System environment:
-------------
- Ubuntu 16.04
- ros kinetic
- gazebo7

Required configuration environment:
--------------
```
sudo apt-get install ros-kinetic-navigation
sudo apt-get install ros-kinetic-slam-gmapping
sudo apt-get install ros-kinetic-teleop-twist-keyboard
```
1.Start the robot world:
-----------
```
roslaunch omni_gazebo omni_world.launch
```
You can teleop the robot by using this command:
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py  
```
2.Start the gmapping:
-----------
```
roslaunch omni_slam omni_gmapping.launch
```
If you find there has some obstacles in RVIZ,you can uncheck the Odometry option to hide them. Next,you can teleop the robot to circle the map.And the command of saving the map is:
```
rosrun map_server map_saver -f map
```
3.Satrt the navigation:
-------------
In this project,I prepare three open source projects:mrobot,turtlebot3 and husky.I create the navigation bag on the basis of this.

- mrobot:
```
roslaunch omni_navigation navigation_mrobot.launch
roslaunch omni_navigation move_base_mrobot.launch
```
- turtlebot3:
```
roslaunch omni_navigation navigation_turtlebot3.launch
roslaunch omni_navigation move_base_turtlebot3.launch
```
- husky:
```
roslaunch omni_navigation navigation_husky.launch
roslaunch omni_navigation move_base_husky.launch
```


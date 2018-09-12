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
Start the robot world:
-----------
```
roslaunch omni_gazebo omni_world.launch
```
You can teleop the robot by using this command:
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py  
```

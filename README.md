# MasterGraduationProgram

### 1.Introduction

 The title of my Master Program is Research on the Stability Control and  Autonomous Landing of Parent Platform of the Child-Parent UAV. 

The main contents include:

- Design of Child-Parent UAV
- Dynamic analysis of Parent UAV under the influence of Child UAV interference and impact load
- Landing area search without ground marker

Directory file structure:

- `piggy_WS`: Launch file of ROS, Parent UAV model, Gazebo world etc.
- `project_ws`: Landing area search algorithm, TF coordinate transformation, Offboard flight control code



### 2.Configure simulation environment

**step1:** Install ROS melodic

**step2:** Install px4

```
cd MasterGraduationProgram/piggy_WS/src/
git clone https://github.com/PX4/PX4-Autopilot.git --recursive Firmware
```

[Install reference](https://docs.px4.io/master/en/dev_setup/dev_env_linux_ubuntu.html#gazebo-jmavsim-and-nuttx-pixhawk-targets)

```
cd ~/
gedit .bashrc
```

Add the followings to the end of `.bashrc`

```
source {Path}/piggy_WS/devel/setup.bash
source {Path}/code/project_ws/devel/setup.bash
source {Path}/piggy_WS/src/Firmware/Tools/setup_gazebo.bash {Path}/piggy_WS/src/Firmware/ {Path}/piggy_WS/src/Firmware/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:{Path}/piggy_WS/src/Firmware
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:{Path}/piggy_WS/src/Firmware/Tools/sitl_gazebo
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:{Path}/Piggy_WS/src/gazebo_world/models
```

**step3:** Launch ROS

```
roslaunch parent_drone parent_drone.launch
```

**step4:** Run Landing area search algorithm

```
rosrun disparity_handle disparity_handle
rosrun visual_landing visual_landing
```


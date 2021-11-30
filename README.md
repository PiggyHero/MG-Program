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
- `ParentUAV_Modelsw.rar`: Parent UAV 3D Model in Solidworks
- `Matlab_Code`: Matlab and Simulink code



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

### 3.Experiment

![image-20211201020207609](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020207.png)

![image-20211201020220112](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020220.png)

### 4.Results

Child-Parent UAV:

![image-20211201015541165](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201015541.png)

Dynamic simulation structure of Parent UAV:

![image-20211201015654072](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201015654.png)

Height variation of the Parent UAV under aerodynamic disturbance conditions of the Child UAV:

![image-20211201015706851](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201015706.png)

Altitude variation of the Parent UAV under aerodynamic disturbance conditions of the Child UAV:

![image-20211201015713332](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201015713.png)

Height variation of the Parent UAV under impact load conditions of the Child UAV:

![image-20211201020101978](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020102.png)

Altitude variation of the Parent UAV under impact load conditions of the Child UAV:

![image-20211201020118146](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020118.png)

Gazebo world: 

![image-20211201020301588](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020301.png)

Landing area search:

![image-20211201020331868](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020331.png)

![image-20211201020340357](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020340.png)

![image-20211201020353051](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020353.png)

![image-20211201020401519](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020401.png)

![image-20211201020407593](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020407.png)

![image-20211201020422968](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020423.png)

![image-20211201020436289](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020436.png)

Selected landing area:

![image-20211201020505990](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020506.png)

![image-20211201020511938](https://raw.githubusercontent.com/PiggyHero/Blog_Picture/master/20211201020511.png)


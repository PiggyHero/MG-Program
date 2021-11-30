
%%%%%%%%%%%%%%%%%%%%
%%% PosCtrl_tune %%%
%%%%%%%%%%%%%%%%%%%%
path('./icon/',path);
%ģ�Ͳ��� ����ģ�ͳ�ʼ���ļ�icon/init.m
Init;

%constant parameters
RAD2DEG=57.2957795;
DEG2RAD=0.0174533;
%Initial condition
ModelInit_PosE=[0,0,-10];
ModelInit_VelB=[0,0,0];
ModelInit_AngEuler=[0,0,0];
ModelInit_RateB=[0,0,0];
ModelInit_RPM=557.1420;

%PID����
Kp_PITCH_ANGLE =6.5%6.5;
Kp_PITCH_AgngleRate = 0.1%0.1;
Ki_PITCH_AgngleRate = 0.10;
Kd_PITCH_AgngleRate = 0.001;
Kp_ROLL_ANGLE =6.5;
Kp_ROLL_AgngleRate = 0.1;
Ki_ROLL_AgngleRate = 0.02;
Kd_ROLL_AgngleRate = 0.001;

Kp_YAW_AngleRate = 0.3;
Ki_YAW_AngleRate = 0.01;
Kd_YAW_AngleRate = 0.00;

%λ�ÿ���
Kpxp=5;Kpxi=0;Kpxd=0.5;
Kpyp=1.0;
Kpzp=5;Kpzi=0.1;Kpzd=0;
Kvxp=5;Kvxi=0.01;Kvxd=0.5;
Kvyp=2.0;Kvyi=0;Kvyd=0.01;
Kvzp=5;Kvzi=0.01;Kvzd=0.005;

Saturation_I_RP_Max=0.3;
Saturation_I_RP_Min=-0.3;
Saturation_I_Y_Max=0.2;
Saturation_I_Y_Min=-0.2;
Saturation_I_ah=3.431;%0.5*g*tan(MAX_CONTROL_ANGLE_ROLL*DEG2RAD);
Saturation_I_az=5;%

%�����ƽǶȣ���λ��
MAX_CONTROL_ANGLE_ROLL = 35;
MAX_CONTROL_ANGLE_PITCH  = 50;
%�����ƽ��ٶ�
MAX_CONTROL_ANGLE_RATE_PITCH = 220;
MAX_CONTROL_ANGLE_RATE_ROLL = 220;
MAX_CONTROL_ANGLE_RATE_Y = 200;

MAX_CONTROL_VELOCITY_XY = 5;
MAX_CONTROL_VELOCITY_Z = 3;
MAX_MAN_THR=0.9;
MIN_MAN_THR=0.05;
THR_HOVER=0.609;


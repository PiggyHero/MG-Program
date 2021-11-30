clear;
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
Kp_PITCH_ANGLE =6.5;
Kp_PITCH_AgngleRate = 0.1;%0.1;
Ki_PITCH_AgngleRate = 0.02;%0.02;
Kd_PITCH_AgngleRate = 0.001;
Kp_ROLL_ANGLE =6.5;
Kp_ROLL_AgngleRate = 0.1;
Ki_ROLL_AgngleRate = 0.02;
Kd_ROLL_AgngleRate = 0.001;

Kp_YAW_AngleRate = 0.3;
Ki_YAW_AngleRate = 0.05;
Kd_YAW_AngleRate = 0.00;

%λ�ÿ���
Kpxp=1.5;
Kixp=0;
Kdxp=0;
Kpyp=1.0;
Kpzp=4.0;
Kvxp=3;Kvxi=0.4;Kvxd=0.01;
Kvyp=10;Kvyi=4.5;Kvyd=2.5;
Kvzp=10;Kvzi=4.5;Kvzd=0;

Saturation_I_RP_Max=0.3;
Saturation_I_RP_Min=-0.3;
Saturation_I_Y_Max=0.2;
Saturation_I_Y_Min=-0.2;
Saturation_I_ah=3.43;%0.5*g*tan(MAX_CONTROL_ANGLE_ROLL*DEG2RAD);
Saturation_I_az=5;%

%�����ƽǶȣ���λ��
MAX_CONTROL_ANGLE_ROLL = 35;
MAX_CONTROL_ANGLE_PITCH  = 35;
%�����ƽ��ٶ�
MAX_CONTROL_ANGLE_RATE_PITCH = 220;
MAX_CONTROL_ANGLE_RATE_ROLL = 220;
MAX_CONTROL_ANGLE_RATE_Y = 200;

MAX_CONTROL_VELOCITY_XY = 10;%ԭ����5
MAX_CONTROL_VELOCITY_Z = 3;%ԭ����3
MAX_MAN_THR=0.9;
MIN_MAN_THR=0.05;
THR_HOVER=0.609;


landonpath;



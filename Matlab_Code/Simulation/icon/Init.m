%Initial condition
ModelInit_PosE=[0,0,0]; %��ʼλ��
ModelInit_VelB=[0,0,0]; %��ʼ�ٶ�
ModelInit_AngEuler=[0,0,0]; %��ʼŷ����
ModelInit_RateB=[0,0,0];    %��ʼ���ٶ�
ModelParam_uavMass=1.4;     %����������
ModelParam_uavJxx = 0.0211; %x����ת������
ModelParam_uavJyy = 0.0219; %y����ת������
ModelParam_uavJzz = 0.0366; %z����ת������
%ת����������
ModelParam_uavJ= [ModelParam_uavJxx,0,0;...
    0,ModelParam_uavJyy,0;...
    0,0,ModelParam_uavJzz];


ModelInit_RPM=0; %�����ʼת��
ModelParam_uavType = int8(3); %������������X�ͣ����嶨����ĵ�"���Ͷ����ĵ�.docx"
ModelParam_uavMotNumbs = int8(4);  %�������
ModelParam_uavR=0.9;   %�������
ModelParam_motorCr=1148; %�������-�ٶ�����б��
ModelParam_motorWb=-141.4;  %�������-�ٶ��������
ModelParam_motorT= 0.02;  %������Ի��ڳ���
ModelParam_motorJm =0.0001287;    %���ת��+������ת������
ModelParam_rotorCm=1.779e-07;    %������Ť��ϵ��
ModelParam_rotorCt=1.105e-05;    %����������ϵ��
ModelParam_motorMinThr=0.05;     %�����������

ModelParam_uavCd = 0 ;% 0.073;   %����ϵ��
ModelParam_uavCCm = [0.01 0.01 0.0055]; %����ϵ������
ModelParam_uavDearo = 0.12;  %����������������ֱ����λ�ò� 
ModelParam_envGravityAcc = 9.8;

ModelParam_GlobalNoiseGainSwitch =1;   %����ˮƽ����

%Environment Parameter
ModelParam_envLongitude = 116.259368300000;  %ȫ��λγ��
ModelParam_envLatitude = 40.1540302;         %ȫ��λ����
ModelParam_GPSLatLong = [ModelParam_envLatitude ModelParam_envLongitude];  %��γ��
ModelParam_envAltitude = -41.5260009765625;     %�ο��߶ȣ�����Ϊ��
ModelParam_BusSampleRate = 0.001;            %ģ�Ͳ�����


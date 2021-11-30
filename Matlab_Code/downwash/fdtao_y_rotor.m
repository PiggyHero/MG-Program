function [tao_y,fd] = fdtao_y_rotor(z,r)%输入子机与母机的距离，输入子机中心与母机中心的垂直距离z，水平距离r，在这里仅仿真x轴方向，输出阻力f和对y轴的力矩tao_y
g=9.8;
M=0.6;  %子机质量600g
rou=1.21; %大气密度
A=pi*(0.1016/2)^2; %桨盘面积 桨盘直径10.16cm
L=0.19;  %轴距0.19m
T=M*g;
Cd=1.18;
Cax=3.612; 
k1=1.105e-05;%螺旋桨拉力系数
b=3.71e-7;
R=0.35;%力臂0.35m
w=557;%悬停时电机转速
Z0=-1.1353;
Crad=24.936;
Vmax_z=sqrt(1.0*T/(2*rou*A))*Cax*L/(z-Z0);
R1=(r-R)^2+R^2;
R2=(r+R)^2+R^2;
Vr1=Vmax_z*exp(-Crad*R1/(z-Z0)^2);
Vr2=Vmax_z*exp(-Crad*R2/(z-Z0)^2);

tao_y=(b*w^2)*Vr1*R-(b*w^2)*Vr2*R;
tao_y=-2*tao_y;
fd=-2*(Vr1*b*w^2+Vr2*b*w^2);









end
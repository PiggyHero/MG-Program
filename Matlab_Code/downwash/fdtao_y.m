function [fd,tao_y] = fdtao_y(z,r)%输入子机与母机的距离，输入子机中心与母机中心的垂直距离z，水平距离r，在这里仅仿真x轴方向，输出阻力f和对y轴的力矩tao_y
g=9.8;
M=0.6;  %子机质量600g
rou=1.21; %大气密度
A=pi*(0.1016/2)^2; %桨盘面积 桨盘直径10.16cm
L=0.19;  %轴距0.19m
T=M*g;
Cd=1.18;
Cax=3.612; 
Z0=-1.1353;
Crad=24.936;
Vmax_z=sqrt(1.0*T/(2*rou*A))*Cax*L/(z-Z0);
X=(-0.25:0.01:0.25);
Y=(0:0.01:0.25);
dA=0.01^2;

tao_y=0;
fd=0;
for i=1:length(X)
    for j=1:length(Y)
        x=X(i);
        y=Y(j);
        fd=fd+0.5*Cd*rou*Vr(x,y)^2*dA;
    end
end
fd=2*fd;

for i=1:length(X)
    for j=1:length(Y)
        x=X(i);
        y=Y(j);
        tao_y=tao_y+0.5*Cd*rou*Vr(x,y)^2*dA*x;
    end
end

tao_y=2*tao_y;

function Vr=Vr(x,y)
R2=(r+x)^2+y^2;
Vr=Vmax_z*exp(-Crad*R2/(z-Z0)^2);
end



end


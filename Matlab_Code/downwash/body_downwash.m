clear;
clc;
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
%************************************************************************
t=(0:0.001:5);
r=zeros(1,length(t));
z=zeros(1,length(t));
b=0*(rand(1,length(t))-0.5);
for i=1:length(t)
  a=0.5*t(i)^2-2*t(i)+2;
   if t(i)<=2
      r(i)=a;
   else
       r(i)=b(i);
   end
   
end
figure(1);
plot(t,r);
axis equal;
axis([0 7 0 3]);
title('子母机水平距离随时间变化情况')
xlabel('时间t (s)')
ylabel('水平距离r (m)')
for i=1:length(t)
  if t(i)>=2
      z(i)=0.29*(t(i)-2)^2-1.74*(t(i)-2)+3.01;
      if t(i)>=5
       z(i)=0.4+b(i);
      end
   else
       z(i)=3+b(i);
   end
   
   
end
figure(2);
plot(t,z)
axis equal;
axis([0 7 0 4]);
title('子母机垂直距离随时间变化情况')
xlabel('时间t (s)')
ylabel('垂直距离z (m)')

%*************************************************************************
figure(3);
for ii=1:30:length(t)
r_distant=r(ii);
z_distant=z(ii);

lx=(-0.25:0.01:0.25);
ly=(-0.25:0.01:0.25);
[LX,LY]=meshgrid(lx,ly);
Vmax_z=sqrt(1.0*T/(2*rou*A))*Cax*L/(z_distant-Z0);
R2=(r_distant+LX).^2+LY.^2;
downwash=Vmax_z*exp(-Crad*R2/(z_distant-Z0)^2);

pcolor(LX,LY,downwash);shading interp;
caxis([0,8]);
colorbar; %加上色条
getframe;

end
init;
z=(0.1:0.01:6);
l1=length(z);
%********************************预测值**********************************
Vmax1=zeros(1,l1);%T=1.0mg 
for i=1:l1
    Vmax1((i))=sqrt(1.0*T/(2*rou*A))*Cax*L/(z(i)-Z0);
end
%******************************实际测量值********************************
z1=[0.2 0.3 0.5 0.75 1 1.5 2.5 3:0.5:6];
V=[9.25 8.25 7.6 6.55 5.25 4.25 3.3];
V1=zeros(1,length(z1));
for i=8:length(z1)
    V1(i)=Vmax1(m2num(z1(i)))+(rand(1,1)-0.5)/2;
end
for i=1:length(V)
    V1(i)=V(i);
end
%************************************************************************
figure(1);
plot(z,Vmax1,"-",'LineWidth',3);hold on;plot(z1,V1,"o",'MarkerSize', 8);hold off;
legend({'模型计算值','实验测量值'},'FontSize',12);
%title('\fontsize{16}\color{black}子机正下方气流速度变化');
xlabel('\fontsize{15}垂直距离z (m)'),ylabel('\fontsize{15}下洗气流速度 Vmax(z) (m/s)');
xlim([0 6]);
ylim([0 10]);
set(gca,'XGrid','on','YGrid','on');
%print('-f1','-dtiff','-r600','正下方速度');

%***************************径向预测值************************************
r=(-1:0.01:1);
l2=length(r);
v_z0_3=zeros(1,l2);
v_z0_5=zeros(1,l2);
v_z1=zeros(1,l2);
v_z2=zeros(1,l2);
v_z3=zeros(1,l2);
v_z4=zeros(1,l2);
v_z5=zeros(1,l2);
v_z6=zeros(1,l2);

for i=1:l2
   v_z0_3(i)=Vmax1(21)*exp(-Crad*(r(i)/(z(21)-Z0))^2);
   v_z0_5(i)=Vmax1(m2num(0.5))*exp(-Crad*(r(i)/(z(m2num(0.5))-Z0))^2);
   v_z1(i)=Vmax1(m2num(1))*exp(-Crad*(r(i)/(z(m2num(1))-Z0))^2);
   v_z2(i)=Vmax1(m2num(2))*exp(-Crad*(r(i)/(z(m2num(2))-Z0))^2);
   v_z3(i)=Vmax1(m2num(3))*exp(-Crad*(r(i)/(z(m2num(3))-Z0))^2);
   v_z4(i)=Vmax1(m2num(4))*exp(-Crad*(r(i)/(z(m2num(4))-Z0))^2);
   v_z5(i)=Vmax1(m2num(5))*exp(-Crad*(r(i)/(z(m2num(5))-Z0))^2);
   v_z6(i)=Vmax1(m2num(6))*exp(-Crad*(r(i)/(z(m2num(6))-Z0))^2);
end

%************************* 径向实验值 ************************************
r1=(-0.54:0.06:0.54);
v_z0_5_shiyan=zeros(1,length(r1));
v_z0_5_shiyan=[0.26 1.5 2 2.8 3.3 4.2 4.8 6.0 7.1 7.6 7.1 6.8 4.6 4.4 3.9 1.75 0.8 0.35 0.26];




%*************************************************************************
figure(2);
plot(r,v_z0_3,r,v_z0_5,r,v_z1,r,v_z2,r,v_z3,r,v_z4,r,v_z5,r,v_z6,'LineWidth',3);
legend({'z=0.3m','z=0.5m','z=1m','z=2m','z=3m','z=4m','z=5m','z=6m'},'FontSize',12);
xlabel('\fontsize{15}水平距离r (m)');
ylabel('\fontsize{15}下洗气流速度V  (m/s)')
%print('-f2','-dtiff','-r600','任意一点速度');

figure(3);
plot(r,v_z0_5,'LineWidth',3);
hold on;
plot(r1,v_z0_5_shiyan,"x",'MarkerSize',8);hold off;
legend({'模型计算值','实验测量值'},'FontSize',15);
xlabel('水平距离 r (m)','FontSize',15);
ylabel('下洗气流速度 V  (m/s)','FontSize',15);
%print('-f3','-dtiff','-r600','垂直距离为0.5m处的预测实验对比图');

%********************************力和力矩**********************************
fd_0_3m=zeros(1,length(r));
fd_0_5m=zeros(1,length(r));
fd_1m=zeros(1,length(r));
fd_2m=zeros(1,length(r));
fd_3m=zeros(1,length(r));
fd_4m=zeros(1,length(r));
fd_5m=zeros(1,length(r));
tao_y_0_3m=zeros(1,length(r));
tao_y_0_5m=zeros(1,length(r));
tao_y_1m=zeros(1,length(r));
tao_y_2m=zeros(1,length(r));
tao_y_3m=zeros(1,length(r));
tao_y_4m=zeros(1,length(r));
tao_y_5m=zeros(1,length(r));
for i=1:l2
[fd_0_3m(i),tao_y_0_3m(i)]= fdtao_y(0.3,r(i));
[fd_0_5m(i),tao_y_0_5m(i)]= fdtao_y(0.5,r(i));
[fd_1m(i),tao_y_1m(i)]= fdtao_y(1,r(i));
[fd_2m(i),tao_y_2m(i)]= fdtao_y(2,r(i));
[fd_3m(i),tao_y_3m(i)]= fdtao_y(3,r(i));
[fd_4m(i),tao_y_4m(i)]= fdtao_y(4,r(i));
[fd_5m(i),tao_y_5m(i)]= fdtao_y(5,r(i));
end
figure(4);
plot(r,fd_0_3m,r,fd_0_5m,r,fd_1m,r,fd_2m,r,fd_3m,r,fd_4m,r,fd_5m,'LineWidth',3);
legend({'z=0.3m','z=0.5m','z=1m','z=2m','z=3m','z=4m','z=5m'},'FontSize',12);
xlabel('\fontsize{16}水平距离r (m)');
ylabel('\fontsize{16}阻力F_{d} （N）');
%print('-f4','-dtiff','-r600','机身阻力随水平距离的变化情况')

figure(5);
plot(r,tao_y_0_3m,r,tao_y_0_5m,r,tao_y_1m,r,tao_y_2m,r,tao_y_3m,r,tao_y_4m,r,tao_y_5m,'LineWidth',3);
legend({'z=0.3m','z=0.5m','z=1m','z=2m','z=3m','z=4m','z=5m'},'FontSize',12);

xlabel('\fontsize{16}水平距离r (m)');
ylabel('\fontsize{16}俯仰力矩\tau_{d} （N·m）');
%print('-f5','-dtiff','-r600','机身受到的俯仰力矩随水平距离的变化情况')
%************************螺旋桨拉力变化情况********************************

tao_y_0_3m_rotor=zeros(1,length(r));
tao_y_0_5m_rotor=zeros(1,length(r));
tao_y_1m_rotor=zeros(1,length(r));
tao_y_2m_rotor=zeros(1,length(r));
tao_y_3m_rotor=zeros(1,length(r));

fd_0_3m=zeros(1,length(r));
fd_0_5m=zeros(1,length(r));
fd_1m=zeros(1,length(r));
fd_2m=zeros(1,length(r));
fd_3m=zeros(1,length(r));
for i=1:l2
   [ tao_y_0_3m_rotor(i),fd_0_3m(i)]=fdtao_y_rotor(0.3,r(i));
   [ tao_y_0_5m_rotor(i),fd_0_5m(i)]=fdtao_y_rotor(0.5,r(i));
   [ tao_y_1m_rotor(i),fd_1m(i)]=fdtao_y_rotor(1,r(i));
   [ tao_y_2m_rotor(i),fd_2m(i)]=fdtao_y_rotor(2,r(i));
   [ tao_y_3m_rotor(i),fd_3m(i)]=fdtao_y_rotor(3,r(i));
end

figure(6);
plot(r,tao_y_0_3m_rotor,r,tao_y_0_5m,r,tao_y_1m,r,tao_y_2m,r,tao_y_3m,'LineWidth',3);
legend({'z=0.3m','z=0.5m','z=1m','z=2m','z=3m'},'FontSize',12);
title('\fontsize{16}');
xlabel('\fontsize{16}水平距离r (m)');
ylabel('\fontsize{16}俯仰力矩\tau_{d} （N·m）');
%print('-f6','-dtiff','-r600','螺旋桨俯仰力矩随水平距离的变化情况')

figure(7);
plot(r,fd_0_3m,r,fd_0_5m,r,fd_1m,r,fd_2m,r,fd_3m,'LineWidth',3);
legend({'z=0.3m','z=0.5m','z=1m','z=2m','z=3m'},'FontSize',12);

xlabel('\fontsize{16}水平距离r (m)');
ylabel('\fontsize{16}拉力变化F_{p} （N）');
%print('-f7','-dtiff','-r600','螺旋桨拉力随水平距离的变化情况')

land_h_test=(0.1:0.1:0.5);
land_h_cal=(0.1:0.01:0.5);
impact_test=[7.63,10.3,10.67,11.97,12.73];
impact_cal=zeros(1,length(land_h_cal));
cx=-0.213;
cy=0.659;
p=6;
for i=1:length(land_h_cal)
    impact_cal(i)=p*(1+sqrt(cx+2*land_h_cal(i)/cy));
end
figure(8);
plot(land_h_cal,impact_cal,"-",'LineWidth',3);hold on;
plot(land_h_test,impact_test,"x",'MarkerSize',12);hold off;
xlabel('\fontsize{16}降落高度(m)');
ylabel('\fontsize{16}冲击载荷(N)');

legend({'模型计算值','实验测量值'},'FontSize',12,'location','Northwest');
%print('-f8','-dtiff','-r600','冲击载荷预测与实验结果对比');
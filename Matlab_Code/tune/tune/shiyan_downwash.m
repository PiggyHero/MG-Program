init_downwash;

z=(0.1:0.01:6);
l1=length(z);
%********************************预测值**********************************
Vmax1=zeros(1,l1);%T=1.0mg 
for i=1:l1
    Vmax1((i))=sqrt(1.0*T/(2*rou*A))*Cax*L/(z(i)-Z0);
end
%******************************实际测量值********************************
z1=[0.2 0.3 0.5 0.75 1 1.5 2.5 3:0.5:6];
V=[9.25 8.25 7.6 6.55 5.25 4.25 3.3];%V是实际测量的根据垂直距离变化的速度
V1=zeros(1,length(z1));%V1前面8个是实际测量的，后i按的是假的
for i=8:length(z1)
    V1(i)=Vmax1(m2num(z1(i)))+(rand(1,1)-0.5)/2;
end
for i=1:length(V)
    V1(i)=V(i);
end
%************************************************************************
figure(1);
plot(z,Vmax1,"-");hold on;plot(z1,V1,"*");hold off;
legend({'预测值','实验值'});
xlim([0 6]);
ylim([0 10]);
set(gca,'XGrid','on','YGrid','on');

%***************************径向预测值************************************
r=(-1:0.01:1);
l2=length(r);
v_z1=zeros(1,l2);
v_z2=zeros(1,l2);
v_z3=zeros(1,l2);
v_z4=zeros(1,l2);
v_z5=zeros(1,l2);
v_z6=zeros(1,l2);

for i=1:l2
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
v_z0_5_shiyan=[0.26 0.35 0.8 1.8 3.9 4.2 4.8 6.45 7.1 7.6 7.1 6.45 4.6 4.4 3.9 1.75 0.8 0.35 0.26];




%*************************************************************************
figure(2);
plot(r,v_z1,r,v_z2,r,v_z3,r,v_z4,r,v_z5,r,v_z6);
legend({'z=1m','z=2m','z=3m','z=4m','z=5m','z=6m'});

figure(3);
plot(r,v_z0_5,r1,v_z0_5_shiyan,"o");
legend({'预测值','测量值'});

function num=m2num(m)
    num=m/0.01-9;
end


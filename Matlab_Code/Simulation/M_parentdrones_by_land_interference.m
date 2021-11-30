%冲击载荷的母机位移和姿态变化


%t=(0:0.001:5);%改时间步长
t=X_position_by_land_interference.Time;
h0=2.6;%子机距离母机初始距离为3-h0
 num=0;
 roundx=zeros(1,32);
 roundy=zeros(1,32);
 for j=0:0.2:2*pi
     num=num+1;
     r=0.03;
     roundx(num)=r*cos(j);
     roundy(num)=r*sin(j);
    
 end
   


transx=0;%机身姿态变化
transy=0;
transz=0;

dx=0;%机身位置变化
dy=0;
dz=0;

%数据采样
pitch=pitch_angle_by_land_interference.Data;
x=X_position_by_land_interference.Data;
z=Z_position_by_land_interference.Data;
pitch=pitch';

x=x';
z=z';

%子机冲击
% h=zeros(1,length(t));
% for ii=1:length(t)
%    if ii<=1000
%     h(ii)=0; 
%    else
%        h(ii)=-0.4;
%    end
% end
  
    
%************************************************************************ 
% figure(1);
% for i=0.9:0.015:3
%     %位置变化
%      dx=-x(t2num(i-0.03))*5;
%      dz=-z(t2num(i))-10;
% 
%       
%     %姿态变化
%     transz=0.25*sin(DEG2RAD*pitch(t2num(i)));%母机的姿态变化
%     transx=-(0.25-0.25*cos(DEG2RAD*pitch(t2num(i)))); %母机的姿态变化
%     transx_down=0.05*sin(DEG2RAD*pitch(t2num(i)));%母机的姿态变化
%     transzrotor=0.34*sin(DEG2RAD*pitch(t2num(i)));%母机螺旋桨的姿态变化
%     transxrotor=-(0.34-0.34*cos(DEG2RAD*pitch(t2num(i)))); %母机螺旋桨姿态变化
%     
%     transz2=0.15*sin(DEG2RAD*pitch(t2num(i)));
%     transx2=-(0.15-0.15*cos(DEG2RAD*pitch(t2num(i))));
%     transx_down2=0.03*sin(DEG2RAD*pitch(t2num(i)));
%    
%     start_Points=[-0.15+2+transx-0.1+dx 0.1+transy 3+10-transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx 0.1+transy 3+10+transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx -0.1+transy 3+10+transz2-h0+dz+h(t2num(i));
%                    -0.15+2+transx-0.1+dx -0.1+transy 3+10-transz2-h0+dz+h(t2num(i));
%                    -0.15+2+transx-0.1+dx+transx_down2 0.1+transy 2.97+10-transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx+transx_down2 0.1+transy 2.97+10+transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx+transx_down2 -0.1+transy 2.97+10+transz2-h0+dz+h(t2num(i));
%                    -0.15+2+transx-0.1+dx+transx_down2 -0.1+transy 2.97+10-transz2-h0+dz+h(t2num(i));
%                    -0.15+2+transx-0.1+dx 0.1+transy 3+10-transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx 0.1+transy 3+10+transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx -0.1+transy 3+10+transz2-h0+dz+h(t2num(i));
%                    -0.15+2+transx-0.1+dx -0.1+transy 3+10-transz2-h0+dz+h(t2num(i));
%                    1.75+dx-transx 0.25 0+10+dz-transz%母机坐标点
%                    2.25+transx+dx 0.25 0+10+dz+transz
%                    2.25+transx+dx -0.25 0+10+dz+transz
%                    1.75+dx-transx -0.25 0+10+dz-transz
%                    1.75+dx-transx 0.25 0+10+dz-transz
%                    2.25+transx+dx 0.25 0+10+dz+transz
%                    2.25+transx+dx -0.25 0+10+dz+transz
%                    1.75+dx-transx -0.25 0+10+dz-transz
%                    1.75+dx-transx+transx_down 0.25 0+10-0.05+dz-transz%母机坐标点
%                    2.25+transx+dx+transx_down 0.25 0+10-0.05+dz+transz
%                    2.25+transx+dx+transx_down -0.25 0+10-0.05+dz+transz
%                    1.75+dx-transx+transx_down -0.25 0+10-0.05+dz-transz
%                    1.75+dx-transx 0.25 0+10+dz-transz
%                    2.25+transx+dx 0.25 0+10+dz+transz
%                    2.25+transx+dx -0.25 0+10+dz+transz
%                    1.75+dx-transx -0.25 0+10+dz-transz];%表示起始点集
%     end_Points=[0.15+2-transx-0.1+dx 0.1+transy 3+10+transz2-h0+dz+h(t2num(i));
%                 0.15+2-transx-0.1+dx -0.1+transy 3+10+transz2-h0+dz+h(t2num(i));
%                 -0.15+2+transx-0.1+dx -0.1+transy 3+10-transz2-h0+dz+h(t2num(i));
%                 -0.15+2+transx-0.1+dx 0.1+transy 3+10-transz2-h0+dz+h(t2num(i));
%                 0.15+2-transx-0.1+dx+transx_down2 0.1+transy 2.97+10+transz2-h0+dz+h(t2num(i));
%                 0.15+2-transx-0.1+dx+transx_down2 -0.1+transy 2.97+10+transz2-h0+dz+h(t2num(i));
%                 -0.15+2+transx-0.1+dx+transx_down2 -0.1+transy 2.97+10-transz2-h0+dz+h(t2num(i));
%                 -0.15+2+transx-0.1+dx+transx_down2 0.1+transy 2.97+10-transz2-h0+dz+h(t2num(i));
%                 -0.15+2+transx-0.1+dx+transx_down2 0.1+transy 2.97+10-transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx+transx_down2 0.1+transy 2.97+10+transz2-h0+dz+h(t2num(i));
%                    0.15+2-transx-0.1+dx+transx_down2 -0.1+transy 2.97+10+transz2-h0+dz+h(t2num(i));
%                    -0.15+2+transx-0.1+dx+transx_down2 -0.1+transy 2.97+10-transz2-h0+dz+h(t2num(i));
%                    2.25+transx+dx 0.25 0+10+dz+transz
%                    2.25+transx+dx -0.25 0+10+dz+transz
%                    1.75-transx+dx -0.25 0+10+dz-transz
%                    1.75-transx+dx 0.25 0+10+dz-transz
%                    1.75-transx-0.08+dx 0.25+0.08 0+10+dz-transzrotor
%                    2.25+transx+0.08+dx 0.25+0.08 0+10+dz+transzrotor
%                    2.25+transx+0.08+dx -0.25-0.08 0+10+dz+transzrotor
%                    1.75-transx-0.08+dx -0.25-0.08 0+10+dz-transzrotor
%                    2.25+transx+dx+transx_down 0.25 0+10-0.05+dz+transz
%                    2.25+transx+dx+transx_down -0.25 0+10-0.05+dz+transz
%                    1.75-transx+dx+transx_down -0.25 0+10-0.05+dz-transz
%                    1.75-transx+dx+transx_down 0.25 0+10-0.05+dz-transz
%                    1.75-transx+dx+transx_down 0.25 0+10-0.05+dz-transz%母机坐标点
%                    2.25+transx+dx+transx_down 0.25 0+10-0.05+dz+transz
%                    2.25+transx+dx+transx_down -0.25 0+10-0.05+dz+transz
%                    1.75-transx+dx+transx_down -0.25 0+10-0.05+dz-transz];%表示终止点集
%                 
%      X=[start_Points(:,1)  end_Points(:,1)]'; 
%      Y=[start_Points(:,2)  end_Points(:,2)]';
%      Z=[start_Points(:,3)  end_Points(:,3)]';
%      
%      plot(X,Z);
%      xlabel('x方向')
%      ylabel('z方向')
%      
%      hold on;
%      axis equal
%      axis([1 3 9 10.5]);
%      frame=getframe;
%      hold off;
%     
%   
%  end

 figure(2);
 plot(t,-z,'LineWidth',3);
 
 ylabel('\fontsize{16}高度Z (m)')
 xlabel('\fontsize{16}时间t (s)')
 print('-f2','-dtiff','-r600','冲击载荷条件下母机的高度变化');
 
%   figure(2);
%   z_1=-0.1*z;
%   z_2=-0.01*z+0.9;
%  plot(t,z_1,t-0.3,z_2,'Linewidth',3);
%  legend('冲击载荷干扰','气动干扰')
%  title('母机高度变化情况');
%  xlim([0 3]);
%  ylim([0.97 1.01]);
%  ylabel('高度Z (m)')
%  xlabel('时间t (s)')
 
  figure(3);
  plot(t,pitch,'LineWidth',3);
  
  ylabel('\fontsize{16}俯仰角θ (°)')
  xlabel('\fontsize{16}时间t (s)')
  print('-f3','-dtiff','-r600','冲击载荷条件下母机的俯仰角度变化')
%  
 figure(4);
 plot(t,-5*x,'LineWidth',3);

 ylabel('\fontsize{16}水平位移X (m)')
 xlabel('\fontsize{16}时间t (s)')
 print('-f4','-dtiff','-r600','冲击载荷条件下母机的x方向位移变化')

 function num=t2num(i)
 num=uint16(i/0.001) +1;
 end
t=(0:0.001:5);
r_child2parent=zeros(1,length(t));%子母机间的水平距离
z_child2parent=zeros(1,length(t));%子母机间垂直距离

omega1=2*pi;
omega2=4*pi;
for i=1:length(t)
    
 if i>1000 
 r_child2parent(i)=0.1*sin(omega1*t(i));
 else
 r_child2parent(i)=1000;
 end
end
figure(1)
plot(t,r_child2parent);
axis equal;
axis([0 5 -1 1]);
title('子母机水平距离随时间变化情况')
xlabel('时间t (s)')
ylabel('水平距离r (m)')

for i=1:length(t)
 
z_child2parent(i)=0.4+0.1*sin(omega2*t(i));
   
end

figure(2);
plot(t,z_child2parent)
axis equal;
axis([0 5 0 0.6]);
title('子母机垂直距离随时间变化情况')
xlabel('时间t (s)')
ylabel('垂直距离z (m)')


%  num=0;
%  roundx=zeros(1,32);
%  roundy=zeros(1,32);
%  for j=0:0.2:2*pi
%      num=num+1;
%      r=0.03;
%      roundx(num)=r*cos(j);
%      roundy(num)=r*sin(j);
%     
%  end
   
% figure(3);
% 
% transx=0;
% transy=0;
% transz=0;
% 
% 
%     
%     for i=0:0.05:2
%     transx=2-r1(t2num(i));
%     start_Points=[-0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx -0.1+transy 3+10+transz
%                    -0.15+transx -0.1+transy 3+10+transz
%                    -0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx -0.1+transy 2.97+10+transz
%                    -0.15+transx -0.1+transy 2.97+10+transz
%                    -0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx -0.1+transy 3+10+transz
%                    -0.15+transx -0.1+transy 3+10+transz
%                    1.75 0.25 0+10%母机坐标点
%                    2.25 0.25 0+10
%                    2.25 -0.25 0+10
%                    1.75 -0.25 0+10
%                    1.75 0.25 0+10
%                    2.25 0.25 0+10
%                    2.25 -0.25 0+10
%                    1.75 -0.25 0+10
%                    1.75 0.25 +10-0.05
%                    2.25 0.25 +10-0.05
%                    2.25 -0.25 +10-0.05
%                    1.75 -0.25 +10-0.05];%表示起始点集
%     end_Points=[0.15+transx 0.1+transy 3+10+transz
%                 0.15+transx -0.1+transy 3+10+transz
%                 -0.15+transx -0.1+transy 3+10+transz
%                 -0.15+transx 0.1+transy 3+10+transz
%                 0.15+transx 0.1+transy 2.97+10+transz
%                 0.15+transx -0.1+transy 2.97+10+transz
%                 -0.15+transx -0.1+transy 2.97+10+transz
%                 -0.15+transx 0.1+transy 2.97+10+transz
%                 -0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx -0.1+transy 2.97+10+transz
%                    -0.15+transx -0.1+transy 2.97+10+transz
%                     2.25 0.25 0+10
%                    2.25 -0.25 0+10
%                    1.75 -0.25 0+10
%                    1.75 0.25 0+10
%                    1.75-0.08 0.25+0.08 0+10
%                    2.25+0.08 0.25+0.08 0+10
%                    2.25+0.08 -0.25-0.08 0+10
%                    1.75-0.08 -0.25-0.08 0+10
%                     2.25 0.25 +10-0.05
%                    2.25 -0.25 +10-0.05
%                    1.75 -0.25 +10-0.05
%                    1.75 0.25 +10-0.05];%表示终止点集
%                 
%      X=[start_Points(:,1)  end_Points(:,1)]'; 
%      Y=[start_Points(:,2)  end_Points(:,2)]';
%      Z=[start_Points(:,3)  end_Points(:,3)]';
%     
%      
%      plot3(X,Y,Z);
%      hold on;
%      axis equal
%      axis([0 2.5 -1 1 9 13]);
%      xlabel('x方向')
%      ylabel('y方向')
%      zlabel('z方向')
%       plot3(roundx+0.075+transx,roundy+0.05+transy,(3+transz)*ones(1,32)+10);
%       plot3(roundx-0.075+transx,roundy+0.05+transy,(3+transz)*ones(1,32)+10);
%       plot3(roundx-0.075+transx,roundy-0.05+transy,(3+transz)*ones(1,32)+10);
%       plot3(roundx+0.075+transx,roundy-0.05+transy,(3+transz)*ones(1,32)+10);
%       
%       plot3(3*roundx+1.75-0.08,3*roundy+0.25+0.08,zeros(1,32)+10);%母机旋翼
%       plot3(3*roundx+2.25+0.08,3*roundy+0.25+0.08,zeros(1,32)+10);
%       plot3(3*roundx+2.25+0.08,3*roundy-0.25-0.08,zeros(1,32)+10);
%       plot3(3*roundx+1.75-0.08,3*roundy-0.25-0.08,zeros(1,32)+10);
%      frame=getframe;
%     hold off;
%   
%   
% 
% 
%     end

  
    
%************************************************************************    
%  for i=2:0.05:6
%      transz=-(2.9-z(t2num(i)));
%     if i>=2
%        transx=2-r1(t2num(i)); 
%     end
%     start_Points=[-0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx -0.1+transy 3+10+transz
%                    -0.15+transx -0.1+transy 3+10+transz
%                    -0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx -0.1+transy 2.97+10+transz
%                    -0.15+transx -0.1+transy 2.97+10+transz
%                    -0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx 0.1+transy 3+10+transz
%                    0.15+transx -0.1+transy 3+10+transz
%                    -0.15+transx -0.1+transy 3+10+transz
%                    1.75 0.25 0+10%母机坐标点
%                    2.25 0.25 0+10
%                    2.25 -0.25 0+10
%                    1.75 -0.25 0+10
%                    1.75 0.25 0+10
%                    2.25 0.25 0+10
%                    2.25 -0.25 0+10
%                    1.75 -0.25 0+10
%                    1.75 0.25 0+10-0.05%母机坐标点
%                    2.25 0.25 0+10-0.05
%                    2.25 -0.25 0+10-0.05
%                    1.75 -0.25 0+10-0.05];%表示起始点集
%     end_Points=[0.15+transx 0.1+transy 3+10+transz
%                 0.15+transx -0.1+transy 3+10+transz
%                 -0.15+transx -0.1+transy 3+10+transz
%                 -0.15+transx 0.1+transy 3+10+transz
%                 0.15+transx 0.1+transy 2.97+10+transz
%                 0.15+transx -0.1+transy 2.97+10+transz
%                 -0.15+transx -0.1+transy 2.97+10+transz
%                 -0.15+transx 0.1+transy 2.97+10+transz
%                 -0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx 0.1+transy 2.97+10+transz
%                    0.15+transx -0.1+transy 2.97+10+transz
%                    -0.15+transx -0.1+transy 2.97+10+transz
%                    2.25 0.25 0+10
%                    2.25 -0.25 0+10
%                    1.75 -0.25 0+10
%                    1.75 0.25 0+10
%                    1.75-0.08 0.25+0.08 0+10
%                    2.25+0.08 0.25+0.08 0+10
%                    2.25+0.08 -0.25-0.08 0+10
%                    1.75-0.08 -0.25-0.08 0+10
%                    2.25 0.25 0+10-0.05
%                    2.25 -0.25 0+10-0.05
%                    1.75 -0.25 0+10-0.05
%                    1.75 0.25 0+10-0.05];%表示终止点集
%                 
%      X=[start_Points(:,1)  end_Points(:,1)]'; 
%      Y=[start_Points(:,2)  end_Points(:,2)]';
%      Z=[start_Points(:,3)  end_Points(:,3)]';
%      
%      plot3(X,Y,Z);
%      xlabel('x方向')
%      ylabel('y方向')
%      zlabel('z方向')
%      hold on;
%      axis equal
%      axis([0 2.5 -1 1 9 13]);
%       plot3(roundx+0.075+transx,roundy+0.05+transy,(3+transz)*ones(1,32)+10);
%       plot3(roundx-0.075+transx,roundy+0.05+transy,(3+transz)*ones(1,32)+10);
%       plot3(roundx-0.075+transx,roundy-0.05+transy,(3+transz)*ones(1,32)+10);
%       plot3(roundx+0.075+transx,roundy-0.05+transy,(3+transz)*ones(1,32)+10);
%       
%       plot3(3*roundx+1.75-0.08,3*roundy+0.25+0.08,zeros(1,32)+10);%母机旋翼
%       plot3(3*roundx+2.25+0.08,3*roundy+0.25+0.08,zeros(1,32)+10);
%       plot3(3*roundx+2.25+0.08,3*roundy-0.25-0.08,zeros(1,32)+10);
%       plot3(3*roundx+1.75-0.08,3*roundy-0.25-0.08,zeros(1,32)+10);
%       
%      frame=getframe;
%     hold off;
%     
%   
%  end
 
%导入到simulink里的位置变化情况
 distance1=[t 
            r_child2parent 
            z_child2parent]';

%  function num=t2num(i)
%  num=uint16(i/0.001) +1;
%  end
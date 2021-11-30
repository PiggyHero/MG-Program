t=(0:0.001:20);


 num=0;
 roundx=zeros(1,32);
 roundy=zeros(1,32);
 for j=0:0.2:2*pi
     num=num+1;
     r=0.03;
     roundx(num)=r*cos(j);
     roundy(num)=r*sin(j);
    
 end
   
figure(3);

transx=0;%机身姿态变化
transy=0;
transz=0;

dx=0;%机身位置变化
dy=0;
dz=0;

%数据采样
pitch=pitch_angle.Data;
x=xx.Data;
z=zz.Data;
pitch=pitch';
x=x';
z=z';

%子机冲击
h=zeros(1,length(t));
for ii=1:length(t)
   if ii<=1000
    h(ii)=0; 
   else
       h(ii)=-0.2;
   end
end
  
    
%************************************************************************    
 for i=0:0.05:5
    %位置变化
     dx=x(t2num(i))*5;
     dz=-z(t2num(i))-10;
    %姿态变化
    transz=0;
    transx=2; 
    
   
    start_Points=[-0.15+transx-0.1+dx 0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx 0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx -0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   -0.15+transx-0.1+dx -0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   -0.15+transx-0.1+dx 0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx 0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx -0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   -0.15+transx-0.1+dx -0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   -0.15+transx-0.1+dx 0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx 0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx -0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   -0.15+transx-0.1+dx -0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                   1.75+dx 0.25 0+10+dz%母机坐标点
                   2.25+dx 0.25 0+10+dz
                   2.25+dx -0.25 0+10+dz
                   1.75+dx -0.25 0+10+dz
                   1.75+dx 0.25 0+10+dz
                   2.25+dx 0.25 0+10+dz
                   2.25+dx -0.25 0+10+dz
                   1.75+dx -0.25 0+10+dz
                   1.75+dx 0.25 0+10-0.05+dz%母机坐标点
                   2.25+dx 0.25 0+10-0.05+dz
                   2.25+dx -0.25 0+10-0.05+dz
                   1.75+dx -0.25 0+10-0.05+dz
                   1.75+dx 0.25 0+10+dz
                   2.25+dx 0.25 0+10+dz
                   2.25+dx -0.25 0+10+dz
                   1.75+dx -0.25 0+10+dz];%表示起始点集
    end_Points=[0.15+transx-0.1+dx 0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                0.15+transx-0.1+dx -0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                -0.15+transx-0.1+dx -0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                -0.15+transx-0.1+dx 0.1+transy 3+10+transz-2.8+dz+h(t2num(i));
                0.15+transx-0.1+dx 0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                0.15+transx-0.1+dx -0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                -0.15+transx-0.1+dx -0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                -0.15+transx-0.1+dx 0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                -0.15+transx-0.1+dx 0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx 0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   0.15+transx-0.1+dx -0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   -0.15+transx-0.1+dx -0.1+transy 2.97+10+transz-2.8+dz+h(t2num(i));
                   2.25+dx 0.25 0+10+dz
                   2.25+dx -0.25 0+10+dz
                   1.75+dx -0.25 0+10+dz
                   1.75+dx 0.25 0+10+dz
                   1.75-0.08+dx 0.25+0.08 0+10+dz
                   2.25+0.08+dx 0.25+0.08 0+10+dz
                   2.25+0.08+dx -0.25-0.08 0+10+dz
                   1.75-0.08+dx -0.25-0.08 0+10+dz
                   2.25+dx 0.25 0+10-0.05+dz
                   2.25+dx -0.25 0+10-0.05+dz
                   1.75+dx -0.25 0+10-0.05+dz
                   1.75+dx 0.25 0+10-0.05+dz
                   1.75+dx 0.25 0+10-0.05+dz%母机坐标点
                   2.25+dx 0.25 0+10-0.05+dz
                   2.25+dx -0.25 0+10-0.05+dz
                   1.75+dx -0.25 0+10-0.05+dz];%表示终止点集
                
     X=[start_Points(:,1)  end_Points(:,1)]'; 
     Y=[start_Points(:,2)  end_Points(:,2)]';
     Z=[start_Points(:,3)  end_Points(:,3)]';
     
     plot3(X,Y,Z);
     xlabel('x方向')
     ylabel('y方向')
     zlabel('z方向')
     hold on;
     axis equal
     axis([1 3 -1 1 9 10.5]);
      plot3(roundx+0.075+transx-0.1+dx,roundy+0.05+transy,(3+transz)*ones(1,32)+10-2.8+dz+h(t2num(i)));
      plot3(roundx-0.075+transx-0.1+dx,roundy+0.05+transy,(3+transz)*ones(1,32)+10-2.8+dz+h(t2num(i)));
      plot3(roundx-0.075+transx-0.1+dx,roundy-0.05+transy,(3+transz)*ones(1,32)+10-2.8+dz+h(t2num(i)));
      plot3(roundx+0.075+transx-0.1+dx,roundy-0.05+transy,(3+transz)*ones(1,32)+10-2.8+dz+h(t2num(i)));
      
      plot3(3*roundx+1.75-0.08+dx,3*roundy+0.25+0.08,zeros(1,32)+10+dz);%母机旋翼
      plot3(3*roundx+2.25+0.08+dx,3*roundy+0.25+0.08,zeros(1,32)+10+dz);
      plot3(3*roundx+2.25+0.08+dx,3*roundy-0.25-0.08,zeros(1,32)+10+dz);
      plot3(3*roundx+1.75-0.08+dx,3*roundy-0.25-0.08,zeros(1,32)+10+dz);
      
     frame=getframe;
    hold off;
    
  
 end
 figure(2);
plot(t,x);
figure(1);
plot(t,z);
 

 function num=t2num(i)
 num=uint16(i/0.001) +1;
 end
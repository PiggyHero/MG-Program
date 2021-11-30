

pitch_angle1=pitch_angle.Data;
position=position_3d.Data;
figure(1);
plot(tout,position(:,1));
title('母机水平方向位置变化情况');
ylabel('水平位置X (m)')
xlabel('时间t (s)')

figure(2);
plot(tout,-position(:,3));
title('母机高度变化情况');
ylabel('高度Z (m)')
xlabel('时间t (s)')

drag=body_drag.Data;
pullforce=rotor_pull.Data;
resultant=resultant_force.Data;
figure(3);
subplot(3,1,1);
plot(tout,-pullforce);
title('螺旋桨拉力','FontSize',12);
 axis([0 3 13 21])
xlabel('时间t (s)');
ylabel('拉力F (N)');

subplot(3,1,2);
plot(tout,drag);
title('机身阻力','FontSize',12);
 axis([0 3 0 7])
xlabel('时间t (s)');
ylabel('阻力F (N)');

subplot(3,1,3);
plot(tout,-resultant);
title('合力','FontSize',12);
 axis([0 3 -0.05 0.05])
xlabel('时间t (s)');
ylabel('合力R (N)');




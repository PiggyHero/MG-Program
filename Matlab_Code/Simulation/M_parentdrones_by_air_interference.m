x=X_position_by_air_interference.Data;%气动干扰下的位移
z=Z_position_by_air_interference.Data;
pitch=pitch_angle_by_air_interference.Data;

figure(3);
plot(t,15*x,'LineWidth',3);
 ylabel('\fontsize{16}水平位移X (m)')
 xlabel('\fontsize{16}时间t (s)')
 print('-f3','-dtiff','-r600','气动干扰条件下母机的水平位移变化');
figure(4);
plot(t,-z,'LineWidth',3);
 ylabel('\fontsize{16}高度Z (m)')
 xlabel('\fontsize{16}时间t (s)')
 print('-f4','-dtiff','-r600','气动干扰条件下母机的高度变化');
figure(5);
plot(t,pitch,'LineWidth',3);
ylabel('\fontsize{16}俯仰角θ (°)')
xlabel('\fontsize{16}时间t (s)')
print('-f5','-dtiff','-r600','气动干扰条件下母机的俯仰角度变化')
t=(0:0.001:20);
m_ziji=0.6;%子机重量
land_distant=0.15;%落点距离
delta_Jyy=zeros(1,length(t));
for ii=1001:length(t)
    delta_Jyy(ii)=m_ziji*land_distant^2;
end
t_Jyy=[t
       delta_Jyy]';
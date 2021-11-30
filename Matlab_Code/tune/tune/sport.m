t=[0:0.001:20];
r=zeros(1,length(t));
z=zeros(1,length(t));
b=0.05*rand(1,length(t));
for i=1:length(t)
  a=0.5*t(i)^2-2*t(i)+2
   if t(i)<=2
      r(i)=a;
   else
       r(i)=b(i);
   end
   
end
% plot(t,r);
for i=1:length(t)
  if t(i)<=3
      z(i)=0.3*t(i)^2-1.8*t(i)+2.9;
   else
       z(i)=0.2+b(i);
   end
   
   
end
plot(t,z)





clc; clear all
x=0:0.001:1;
y=(10*(x+0.5).^12).*(x>=0&x<0.31)+0.8*(x>=0.31);
plot(x,y,'b','linewidth',5)
hold on;
plot(0,1,'MarkerSize',5);
%axis([0 1 0 1.1])
grid on
X=0:0.1:1;
Y=0:0.1:1;
set(gca,'FontSize',18,'xtick',X,'ytick',Y);
xlabel('1-p','FontName','Times New Roman','FontSize',30);
ylabel('I_\infty','FontName','Times New Roman','FontSize',30,'Rotation',90);
grid on;
title('SIR','FontSize',25);
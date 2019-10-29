line([0,1],[1,1],'LineWidth',5,'color','b');
hold on;
plot(0,0,'MarkerSize',5);
%plot(x,y,'-.ob','LineWidth',2,'MarkerFaceColor','m','MarkerSize',2)
X=0:0.1:1;
Y=0:0.1:1;
set(gca,'FontSize',18,'xtick',X,'ytick',Y);
xlabel('1-p','FontName','Times New Roman','FontSize',30);
ylabel('I_\infty','FontName','Times New Roman','FontSize',30,'Rotation',90);
grid on;
title('SI','FontSize',25);
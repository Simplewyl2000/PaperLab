x=0:0.01:0.3;
y1=[1,1,0.990124,0.9803,0.97014,0.949806,0.939581,0.929317,0.929317,0.919364,0.90954,0.899612,0.889866,0.880804,0.861324,0.851357,0.841378,0.831786,0.822182,0.812384,0.798772,0.788948,0.779124,0.768731,0.758351,0.751215,0.741223,0.731282,0.721044,0.710173,0.700362;1,1,0.510639,0.497841,0.490318,0.479305,0.470308,0.469933,0.465654,0.460535,0.454434,0.447906,0.444571,0.437216,0.426047,0.421639,0.416326,0.410613,0.404124,0.398164,0.392231,0.390111,0.385005,0.379395,0.372092,0.368343,0.360975,0.35614,0.35371,0.347867,0.341817];
bar(x,y1');
X=0:0.03:0.3;
Y=0:0.1:1;
set(gca,'FontSize',16,'xtick',X,'ytick',Y);
title('Slashdot','FontSize',25);
xlabel('1-p','FontName','Times New Roman','FontSize',25);
ylabel('The giant components','FontName','Times New Roman','FontSize',25,'Rotation',90);
h=legend('no search engine','with search engine','location','NorthEast');
set(h,'Fontsize',20);
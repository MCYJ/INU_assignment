a=5;
b=500;
% 평균이 500, 표준편차가 5
y=a*randn(1000, 1)+b;
histogram(y);
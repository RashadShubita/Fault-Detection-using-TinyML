clc 
clear all
N  = 2048;
Fs = 16000;
t = 0:N-1;
t = t/Fs;
F = 100;
x = sin(2*pi*t*F);
noise =awgn(x,1);
%%z  = x + noise;
Fx = doFilter(noise);
subplot(3,1,1);plot(t,x);title('Original Signal');
subplot(3,1,2);plot(t,noise);title('Noisy Signal');
subplot(3,1,3);plot(t,Fx);title('Filterd Signal');
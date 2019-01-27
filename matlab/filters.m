format long;
clc; 
clear all;
close all;

n = 8; % filter order
fn = 24000; % Nyquist frequency

% lowpass
f_lowpass = [0 0.2 0.4 1];  
a_lowpass = [1 0.8  0 0]; 

% highpass
f_highpass = [0 0.2 0.4 1];  
a_highpass = [0 0 0.8 1]; 

% bandpass
f_bandpass = [0 0.2 0.3 0.4 0.45 1];  
a_bandpass = [0 0.8 1 1 0.2 0];  

b_lowpass = firpm(n, f_lowpass, a_lowpass);
b_highpass = firpm(n, f_highpass, a_highpass);
b_bandpass = firpm(n, f_bandpass, a_bandpass);

fprintf("Lowpass coefficients: ")
fprintf("%.8f, ", b_lowpass)
fprintf("\nHighpass coefficients: ")
fprintf("%.8f, ", b_highpass)
fprintf("\nBandpass coefficients: ")
fprintf("%.8f, ", b_bandpass)

fvtool(b_lowpass, 1)
fvtool(b_highpass, 1)
fvtool(b_bandpass, 1)

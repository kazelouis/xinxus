%% --------------------------------------------Part 2.1 --------------------------------------------------%
load mr_lab         		% contains matrices I1 and I2
% Given parameters : I1 proton density 100; I2 proton density 50

I3=I1+I2;
I3=I3+randn(size(I3)).*5;    	% gaussian noise of 5
imagesc(I3);                		 % display image
title('I3 Signal Image with Gaussian Noise Applied')


% SNR and CNR
crop_1 = imcrop(I3);
crop_2 = imcrop(I3);
crop = imcrop(I3);   

snr_1 = mean2(crop_1)/ std2(crop)  	 %mean of array / standard deviation of array
snr_2 = mean2(crop_2)/ std2(crop)   	 %mean of array / standard deviation of array
cnr = (mean2(crop_1) - mean2(crop_2))/ std2(crop)

%SNR1 = 19.7673
%SNR2 = 10.0128
%CNR = 9.8356

%% --------------------------------------------Part 2.2 --------------------------------------------------%
TE= 20;             		%milliseconds
I4= I1*exp(-TE/10);
I5= I2*exp(-TE/50);  

I6 = I4 + I5;
I6 =I6+randn(size(I6)).*5;    	% gaussian noise of 5
imagesc(I6)                   		% display image
title('T2 Weighted Signal Image with Gaussian Noise Applied')

% SNR and CNR
crop_3 = imcrop(I6);
crop_4 = imcrop(I6);
crop_b = imcrop(I6);  

snr_3 = mean2(crop_3)/ std2(crop_b)   %mean of array / standard deviation of array
snr_4 = mean2(crop_4)/ std2(crop_b)   %mean of array / standard deviation of array
cnr2 = ( mean2(crop_3) - mean2(crop_4))/ std2(crop_b)  

%SNR3 = 2.7273
%SNR4 = 6.8961
%CNR2 = 4.1689

%% --------------------------------------------Part 2.3 --------------------------------------------------%

TE2 = 8.664339757;      						% In milliseconds 
I7= I1*exp(-TE2/10);
I8= I2*exp(-TE2/50);  

I9 = I7 + I8;
I9 =I9+randn(size(I9)).*5;    					% gaussian noise of 5
imagesc(I9)                   						% display image
title('Signal Image with Zero Weighted Contrast and Gaussian Noise Applied')

% SNR and CNR
crop_5 = imcrop(I9);
crop_6 = imcrop(I9);
crop_c = imcrop(I9);  

snr_5 = mean2(crop_5)/ std2(crop_c)   %mean of array / standard deviation of array
snr_6 = mean2(crop_6)/ std2(crop_c)   %mean of array / standard deviation of array
cnr3 = ( mean2(crop_5) - mean2(crop_6))/ std2(crop_c)  

%SNR5 = 8.3581
%SNR6 = 8.3045
%CNR3 = 0.0536


MATLAB Code for Part 4
%% --------------------------------------------Part 4.1 --------------------------------------------------%
load T1andT2.mat
plot(TE, T2signal, '.')
xlabel('time (ms)')
ylabel('signal')
title('Plot 4.1')

% --------------------------------------------Part 4.2 --------------------------------------------------%
T1_inv = [-1,-1,1,1,1,1,1,1,1].*T1signal
plot(TI, T1signal, '.', TI,T1_inv, 'o')
xlabel('time (ms)')
ylabel('signal')
title('Plot 4.2')
legend('Original Data', 'Corrected Data')


%%

%Part2 question 3

syms PA PB T2_A T2_B T_echo

PA = 100;
PB = 50;
T2_A = 10;
T2_B = 50;

eqn =( (PA*(exp(-(T_echo)/T2_A)))== PB*(exp(-(T_echo)/T2_B)));
T = solve(eqn, T_echo)







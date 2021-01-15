%MATLAB CODE BME595 LAB2 Part1%

% -----------------------Section 1-1 to 1-4 ----------------------%

load mr_lab;

figure(1)
imagesc(abs(k_space))
colormap(gray(256))
colorbar;
brighten(0.6)
title('K-space')
axis image 
axis off
xlabel('Kx')
ylabel('Ky')

%RESULTING IMAGE MATRIX CALLED image%
figure(2)
img=(fft2(k_space))
image=abs(img)
imagesc(image)
title('MR Image Matrix')
xlabel('x')
ylabel('y')
axis image
colorbar

%ROI CREATE MASK%
roi_meas

%Signal in center of left hemisphere: Mean in Roi is 4282162, Standard Deviation is 105244
%Noise in left bottom corner: Mean in Roi is 304610, Standard Deviation is 39845
%SNR = 107.47

%%
%------------------- Section 1-5 and 1-6-------------------------%

load mr_lab;

%REDUCE RESOLUTION BY 50% in both x and y
k_space_new=k_space(1:2:end, 1:2:end);

figure(3)
imagesc(abs(k_space_new))
colormap(gray(256))
colorbar;
brighten(0.6)
title('K-space with reduced resolution in kx and ky')
axis image 
axis off

figure(4)
img1=(fft2(k_space_new))
image1=abs(img1)
imagesc(image1)
title('MR Image with reduced resolution')
xlabel('x')
ylabel('y')
axis image
colorbar

%ROI CREATE MASK%
roi_meas

%Signal in center of left hemisphere region: Mean in Roi is 4230944, Standard Deviation is 131788
%Noise in left bottom corner: Mean in Roi is 302692, Standard Deviation is 42626
%SNR = 99.26

%%
%------------------- Section 1-7 to 1-9 ----------------------------%

load mr_lab;

%REDUCED FOV IN ONE DIRECTION
k_space_new2=k_space(1:2:end, :);


figure(5)
imagesc(abs(k_space_new2))
colormap(gray(256))
colorbar;
brighten(0.6)
title('K-space with reduced FOV')
axis image 
axis off

figure(6)
img2=(fft2(k_space_new2))
image2=abs(img2)
imagesc(image2)
title('MR Image with reduced FOV ')
xlabel('x')
ylabel('y')
axis image
colorbar

%ROI CREATE MASK%
roi_meas

%Signal in center of left hemisphere region: Mean in Roi is 4221191, Standard Deviation is 136397
%Noise in left bottom corner: Mean in Roi is 309814, Standard Deviation is 49448
%SNR = 85.37

%%
%------------------- Section 1-10 ----------------------------%

load mr_lab;

%CENTRAL K-SPACE AROUND DC FREQUENCY RETAINED
%RESOLUTION UNCHANGED, NULL EVERYTHING BUT CENTER

k_space_5=zeros(224, 224);
k_space_15=zeros(224, 224);
k_space_25=zeros(224, 224);
k_space_50=zeros(224, 224);

k_space_5(110:114, 110:114)=k_space(110:114, 110:114);
k_space_15(105:119, 105:119)=k_space(105:119, 105:119);
k_space_25(100:124, 100:124)=k_space(100:124, 100:124);
k_space_50(87:136, 87:136)=k_space(87:136, 87:136);

%------------------- Section 1-11 ----------------------------%

%CENTRAL K-SPACE NULLED TO ZERO
%RESOLUTION UNCHANGED
% k_space_5=k_space;
% k_space_15=k_space;
% k_space_25=k_space;
% k_space_50=k_space;
% k_space_5(110:114, 110:114)=[0];
% k_space_15(105:119, 105:119)=[0];
% k_space_25(100:124, 100:124)=[0];
% k_space_50(87:136, 87:136)=[0];

%-------------------------------------------------------------%

%figure(7)
%imagesc(abs(k_space_5))
%colormap(gray(256))
%colorbar;
%brighten(0.6)
%title('Low frequency region of k-space')
%axis image; axis off

img5=(fft2(k_space_5))
img15=(fft2(k_space_15))
img25=(fft2(k_space_25))
img50=(fft2(k_space_50))

image5=abs(img5)
image15=abs(img15)
image25=abs(img25)
image50=abs(img50)

figure (11)
imagesc(image5)
title('MR image constructed with k-space sized 5px by 5px')
xlabel('x')
ylabel('y')
axis image
colorbar

figure (12)
imagesc(image15)
title('MR image constructed with k-space sized 15px by 15px')
xlabel('x')
ylabel('y')
axis image
colorbar

figure (13)
imagesc(image25)
title('MR image constructed with k-space sized 25px by 25px')
xlabel('x')
ylabel('y')
axis image
colorbar

figure (14)
imagesc(image50)
title('MR image constructed with k-space sized 50px by 50px')
xlabel('x')
ylabel('y')
axis image
colorbar




clear 
clc
close all

%% What this script do ?
%  Find and visualize fetures(peaks,rms,mean) for a single buffer of data 

%% Read audio data and Sampling rate and remove first 20 buff
[Fault_1_Data,Fs(1)]  = audioread('M1_F2_S1.flac');
Fault_1_Data = Fault_1_Data((20*2048)+1:end, 1);

%% Read the number of sample in each audio data
 SampleSize(1)    = numel(Fault_1_Data);

%% Pre-process data 
BufferLen = 2048;

re = rem(SampleSize(1),BufferLen)
Fault_1_Data = Fault_1_Data(1:SampleSize(1)-re,1);
NumOfRaw = (SampleSize(1)-re)/BufferLen ;

% Fault_1_Data = reshape(Fault_1_Data,[BufferLen, NumOfRaw ])';
% DataBuff = Fault_1_Data(5,1:BufferLen);
% 
% %% Process data and set axis
% w = hann(BufferLen)';
% DataBuff = DataBuff .* w;
% 
% fAxis_F1 = 0:(BufferLen-1)/2;
% fAxis_F1 = fAxis_F1*Fs(1)/BufferLen;
% 
% %% Extract the fetures
% BuffFault_Mean = mean(DataBuff);
% 
% BuffFault_RMS = rms(DataBuff);
% DataFFT = abs(fft(DataBuff));
% DataFFT   = DataFFT(1,1:BufferLen/2);
% 
% 
% num = 3;
% pro = 1;
% 
% [pks, locs] = findpeaks(DataFFT,fAxis_F1,'npeaks',num, 'SortStr','descend',"MinPeakProminence",pro);
% 
% numel(pks)
% %% Plot data
% %plot(fAxis_F1, DataFFT1)
% 
% findpeaks(DataFFT,fAxis_F1, 'npeaks',num, 'SortStr','descend',"MinPeakProminence",pro);
% text(locs,pks,num2str((1:numel(pks))'));
% xlim([0 5000]);



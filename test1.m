clear 
clc
close all
%% 
[Fault_1_Data,FS]  = audioread('M1_F1_S1.flac');

% time domain
 t = linspace(0, length(Fault_1_Data)/FS, length(Fault_1_Data));
 figure;
 plot(t,Fault_1_Data(:,1));
title('Time Domain')
 xlabel('time')
 xlabel('amplitude')

% freq domain
nfft = 1024;

f = linspace(0, FS, nfft);
Y = abs(fft(Fault_1_Data(:,1),nfft));
figure;
plot(f(1:nfft/2), Y(1:nfft/2));
title('freq Domain')
xlabel('freq')
ylabel('abs')

%% 
[audio_in,audio_freq_sampl]=audioread('M1_F1_S1.flac');
Length_audio=length(audio_in);
df=audio_freq_sampl/Length_audio;
frequency_audio=-audio_freq_sampl/2:df:audio_freq_sampl/2-df;
figure
FFT_audio_in=fftshift(fft(audio_in(:,1)))/length(fft(audio_in(:,1)));
plot(frequency_audio,abs(FFT_audio_in));
title('FFT of Input Audio');
xlabel('Frequency(Hz)');
ylabel('Amplitude');


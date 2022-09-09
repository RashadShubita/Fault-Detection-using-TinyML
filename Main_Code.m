clear 
clc
close all

BufferLen = 2048;

%% Read audio data and Sampling rate
% Fault_1_Data(row=sample,column= mic input channel)
[Fault_1_Data,Fs(1)]  = audioread('M1_OFF_S1.flac');
[Fault_2_Data,Fs(2)]  = audioread('M1_H_S1.flac');
[Fault_3_Data,Fs(3)]  = audioread('M1_F1_S1.flac');
[Fault_4_Data,Fs(4)]  = audioread('M1_F2_S1.flac');
[Fault_5_Data,Fs(5)]  = audioread('M1_F3_S1.flac');


%% Extract one input audio signal insted of double mic input and neglect first 20 buffer 
Fault_1_Data = Fault_1_Data((20*BufferLen)+1:end, 1);
Fault_2_Data = Fault_2_Data((20*BufferLen)+1:end, 1);
Fault_3_Data = Fault_3_Data((20*BufferLen)+1:end, 1);
Fault_4_Data = Fault_4_Data((20*BufferLen)+1:end, 1);
Fault_5_Data = Fault_5_Data((20*BufferLen)+1:end, 1);

%% Read the number of sample in each audio data and store data in new array
SampleSize(1)    = numel(Fault_1_Data);
SampleSize(2)    = numel(Fault_2_Data);
SampleSize(3)    = numel(Fault_3_Data);
SampleSize(4)    = numel(Fault_4_Data);
SampleSize(5)    = numel(Fault_5_Data);

re = rem(SampleSize(1),BufferLen)
Fault_1_Data = Fault_1_Data(1:SampleSize(1)-re,1);
NumOfRaw1 = (SampleSize(1)-re)/BufferLen ;

re = rem(SampleSize(2),BufferLen)
Fault_2_Data = Fault_2_Data(1:SampleSize(2)-re,1);
NumOfRaw2 = (SampleSize(2)-re)/BufferLen ;

re = rem(SampleSize(3),BufferLen)
Fault_3_Data = Fault_3_Data(1:SampleSize(3)-re,1);
NumOfRaw3 = (SampleSize(3)-re)/BufferLen ;

re = rem(SampleSize(4),BufferLen)
Fault_4_Data = Fault_4_Data(1:SampleSize(4)-re,1);
NumOfRaw4 = (SampleSize(4)-re)/BufferLen ;

re = rem(SampleSize(5),BufferLen)
Fault_5_Data = Fault_5_Data(1:SampleSize(5)-re,1);
NumOfRaw5 = (SampleSize(5)-re)/BufferLen ;

%% Pre-process data 
Fault_1_Data = reshape(Fault_1_Data,[BufferLen, NumOfRaw1])';
Fault_2_Data = reshape(Fault_2_Data,[BufferLen, NumOfRaw2])';
Fault_3_Data = reshape(Fault_3_Data,[BufferLen, NumOfRaw3])';
Fault_4_Data = reshape(Fault_4_Data,[BufferLen, NumOfRaw4])';
Fault_5_Data = reshape(Fault_5_Data,[BufferLen, NumOfRaw5])';

%%
NumberOfBuff(1) = NumOfRaw1;
NumberOfBuff(2) = NumOfRaw2;
NumberOfBuff(3) = NumOfRaw3;
NumberOfBuff(4) = NumOfRaw4;
NumberOfBuff(5) = NumOfRaw5;

TotalBuff = sum(NumberOfBuff);


RMS = zeros(1,TotalBuff);
Mean = zeros(1,TotalBuff);
Median = zeros(1,TotalBuff);
Variance = zeros(1,TotalBuff);
Skewness = zeros(1,TotalBuff);
Kurtosis = zeros(1,TotalBuff);
CrestFactor = zeros(1,TotalBuff);
ShapeFactor = zeros(1,TotalBuff);
ImpulseFactor = zeros(1,TotalBuff);
MarginFactor = zeros(1,TotalBuff);

pks1 = zeros(1,TotalBuff);
pks2 = zeros(1,TotalBuff);
pks3 = zeros(1,TotalBuff);
locs1 = zeros(1,TotalBuff);
locs2 = zeros(1,TotalBuff);
locs3 = zeros(1,TotalBuff);

indx = 1;
FaltID = ones(TotalBuff,1);

for i=1:NumberOfBuff(1)-1
DataBuff = Fault_1_Data(i,1:BufferLen);
[RMS(indx),Mean(indx),Median(indx),Variance(indx),Skewness(indx),Kurtosis(indx),... 
 CrestFactor(indx),ShapeFactor(indx),ImpulseFactor(indx),MarginFactor(indx), ... 
 pks1(indx),pks2(indx),pks3(indx),locs1(indx),locs2(indx),locs3(indx)] = ExtractFetures(DataBuff,BufferLen,Fs(1));
 indx = indx + 1;
end
for i=1:NumberOfBuff(2)
DataBuff = Fault_2_Data(i,1:BufferLen);
[RMS(indx),Mean(indx),Median(indx),Variance(indx),Skewness(indx),Kurtosis(indx),... 
 CrestFactor(indx),ShapeFactor(indx),ImpulseFactor(indx),MarginFactor(indx), ... 
 pks1(indx),pks2(indx),pks3(indx),locs1(indx),locs2(indx),locs3(indx)] = ExtractFetures(DataBuff,BufferLen,Fs(2));
 indx = indx + 1;
FaltID(indx) = FaltID(indx) + 1;
end
for i=1:NumberOfBuff(3)    
DataBuff = Fault_3_Data(i,1:BufferLen);
[RMS(indx),Mean(indx),Median(indx),Variance(indx),Skewness(indx),Kurtosis(indx),... 
 CrestFactor(indx),ShapeFactor(indx),ImpulseFactor(indx),MarginFactor(indx), ... 
 pks1(indx),pks2(indx),pks3(indx),locs1(indx),locs2(indx),locs3(indx)] = ExtractFetures(DataBuff,BufferLen,Fs(3));
 indx = indx + 1;
FaltID(indx) = FaltID(indx) + 2;
end
for i=1:NumberOfBuff(4)    
DataBuff = Fault_4_Data(i,1:BufferLen);
[RMS(indx),Mean(indx),Median(indx),Variance(indx),Skewness(indx),Kurtosis(indx),... 
 CrestFactor(indx),ShapeFactor(indx),ImpulseFactor(indx),MarginFactor(indx), ... 
 pks1(indx),pks2(indx),pks3(indx),locs1(indx),locs2(indx),locs3(indx)] = ExtractFetures(DataBuff,BufferLen,Fs(4));
 indx = indx + 1;
FaltID(indx) = FaltID(indx) + 3;
end
for i=1:NumberOfBuff(5)    
DataBuff = Fault_5_Data(i,1:BufferLen);
[RMS(indx),Mean(indx),Median(indx),Variance(indx),Skewness(indx),Kurtosis(indx),... 
 CrestFactor(indx),ShapeFactor(indx),ImpulseFactor(indx),MarginFactor(indx), ... 
 pks1(indx),pks2(indx),pks3(indx),locs1(indx),locs2(indx),locs3(indx)] = ExtractFetures(DataBuff,BufferLen,Fs(4));
 indx = indx + 1;
FaltID(indx) = FaltID(indx) + 4;
end
%%

varNames = {'RMS','Mean','Median','Variance','Skewness','Kurtosis', ... 
            'CrestFactor','ShapeFactor','ImpulseFactor','MarginFactor', ...
            'Peak1','Peak2','Peak3','PeakLocs1','PeakLocs2','PeakLocs3','FalutID'};
TaData = table(RMS',Mean',Median',Variance',Skewness',Kurtosis', ... 
               CrestFactor',ShapeFactor',ImpulseFactor',MarginFactor', ... 
               pks1',pks2',pks3',locs1',locs2',locs3',FaltID,'VariableNames',varNames);

% now we use TaData with Classification learner app


%saveCompactModel(trainedModel.ClassificationKNN, 'myKNN_2')
%DataToClasify = TaData(8,1:8);
%PredicttionNdata = classifyX(DataToClasify)


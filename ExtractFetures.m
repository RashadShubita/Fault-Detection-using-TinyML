function [SigRMS,SigMean,SigMedian,SigVariance,SigSkewness,SigKurtosis, ... 
          SigCrestFactor,SigShapeFactor,SigImpulseFactor,SigMarginFactor, ... 
          pks1,pks2,pks3,locs1,locs2,locs3] = ExtractFetures(DataBuff,BufferLen,Fs)

w = hann(BufferLen)'; 
DataBuff = DataBuff .* w;
DataBuff = doFilterHP(DataBuff);
%DataBuff = doFilterLP(DataBuff);

fAxis_F1 = 0:(BufferLen-1)/2;
fAxis_F1 = fAxis_F1*Fs/BufferLen;

SigRMS      =rms(DataBuff);
SigMean     = mean(DataBuff);% not important
Abs     = abs(DataBuff);
MeanAbs = mean(Abs);
Max     = max(DataBuff);
SigMedian   = median(DataBuff);% not important
SigVariance = var(DataBuff);
SigSkewness = skewness(DataBuff);% not important
SigKurtosis = kurtosis(DataBuff);      % Matlab Gen.
SigCrestFactor = peak2rms(DataBuff); 
SigShapeFactor   = SigRMS/MeanAbs;
SigImpulseFactor = Max/MeanAbs;
SigMarginFactor  = Max/(MeanAbs^2);

DataFFT = abs(fft(DataBuff));
DataFFT   = DataFFT(1,1:BufferLen/2);
[pks, locs] = findpeaks(DataFFT,fAxis_F1,'npeaks',3, 'SortStr','descend',"MinPeakProminence",1);
NumPks = numel(pks);
if NumPks == 0
    pks1=0;
    pks2=0;
    pks3=0;
    locs1=0;
    locs2=0;
    locs3=0;
 elseif NumPks == 1
    pks1  = pks;
    locs1 = locs;   
    pks2  = 0;
    locs2 = 0;  
    pks3  = 0;
    locs3 = 0;
 elseif NumPks == 2 
    pks1  = pks(1);
    locs1 = locs(1);  
    pks2  = pks(2);
    locs2 = locs(2);  
    pks3  = 0;
    locs3 = 0;    
 elseif NumPks == 3
    pks1  = pks(1);
    locs1 = locs(1);  
    pks2  = pks(2);
    locs2 = locs(2);  
    pks3  = pks(3);
    locs3 = locs(3);  
end   

end


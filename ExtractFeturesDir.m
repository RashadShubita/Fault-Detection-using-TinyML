function [pks1,pks2,pks3,locs1,locs2,locs3] = ExtractFeturesDir(DataFFT,MinPeakProminence)

%set Buffer lentgh and Sampling Freqancy
%Buffer lentgh same as used to cal. FFT but DataFFT can be different
BufferLen = 2048;   
Fs = 16000;
NumOfPinUsed = 330;

fAxis = 0:NumOfPinUsed-1;
fAxis = fAxis*Fs/BufferLen;

[pks, locs] = findpeaks(DataFFT,fAxis,'npeaks',3, 'SortStr','descend',"MinPeakProminence",MinPeakProminence);
NumPks = numel(pks);
if NumPks == 0
    pks1=0;
    pks2=0;
    pks3=0;
    locs1=0;
    locs2=0;
    locs3=0;
 elseif NumPks == 1
    pks1  = pks(1);
    locs1 = locs(1);   
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
else%if NumPks == 3
    pks1  = pks(1);
    locs1 = locs(1);  
    pks2  = pks(2);
    locs2 = locs(2);  
    pks3  = pks(3);
    locs3 = locs(3);  
end   

end


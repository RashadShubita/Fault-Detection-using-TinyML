clear 
clc
close all

%Open the file for reading, and obtain the file identifier, fileID.
fileID = fopen('SDcard.txt','r');
%Define the format of the data to read. Use '%f' to specify floating-point numbers.
formatSpec = '%f';
%Read the file data, filling output array, A, in column order. fscanf reapplies the format, formatSpec, throughout the file.
Data = fscanf(fileID,formatSpec);
%Close the file.
fclose(fileID);
FeturesSize     = numel(Data);
Data = reshape(Data,[9, FeturesSize/9])';

varNames = {'RMS','Mean','Peak1','Peak2','Peak3','PeakLocs1','PeakLocs2','PeakLocs3','FalutID'};

TaData = table(Data(1:end,2),Data(1:end,3),Data(1:end,4),Data(1:end,5),Data(1:end,6),Data(1:end,7),Data(1:end,8),Data(1:end,9),Data(1:end,1),'VariableNames',varNames);
%saveCompactModel(trainedModel.ClassificationTree, 'myTree_1')



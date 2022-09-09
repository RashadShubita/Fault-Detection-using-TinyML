function label = classifyX (X) %#codegen 
%CLASSIFYX Classify using KNN Model 
%  CLASSIFYX classifies the measurements in X 
%  using the KNN model in the file myKNN.mat, and then 
%  returns class labels in label.

CompactMdl = loadCompactModel('myTree_1'); 
label = predict(CompactMdl,X); 
end
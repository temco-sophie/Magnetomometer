function cvVal = findCV (resultant)
% This function calculates the coefficient of variation (CV)
% INPUT resultant -> input vector
% OUTPUT cvVal -> scalar, coefficient of variation value

% Finding MEAN
meanVal = mean(resultant);%#codegen

% Finding standard deviation
varVal = std(resultant(:));%standard deviation

% Finding Coeeficient of variation
cvVal=varVal/meanVal;%test_obtData
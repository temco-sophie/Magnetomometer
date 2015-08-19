function [cvVal_all,avg_all]= checkInitialState(resultant,speed_box)
    initialVal=resultant(1:50,:);
    boxVal=resultant(50:50+speed_box,:);
    lastVal=resultant(50+speed_box:end,:);
    cvVal1=findCV(initialVal);
    cvVal2=findCV(boxVal);
    cvVal3=findCV(lastVal);
    cvVal_all=[cvVal1 cvVal2 cvVal3];
    avg1=mean(initialVal);
    avg2=mean(boxVal);
    avg3=mean(lastVal);
    avg_all=[avg1 avg2 avg3];    
end
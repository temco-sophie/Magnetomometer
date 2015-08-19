clc;
clear all;
close all;
%%%some parameters
ref_speed_box=150; %Set for test purpose: The assumption is desired box is active in opto range for 3 second 
variation_box=50;
ref_cv=0.05;
% variation_cv=0.01;
max_cv=0.09;
xl_name= 'real_data.xlsx';
sheet_name='all the data';
roller_type = 'always'; % 'always' is for always spinning roller &
                        %'conditional'is for roller that rotates only in box presence
                        %'unknown' is for not to consider roller effect

%% Checking Spreadsheet data..........
% display('Checking Spreadsheet data..........');
test1=xlsread(xl_name,sheet_name); % Read numeric data from 'all the data' sheet of 'test1.xls file'
test_obtData=dataRead(test1);
% resultant = find_resultant(test_obtData);
single_boxData=abstractBox(test_obtData);% Finding a particular box data
test_obtData1=single_boxData{5}; % Taking random box for analysis
speed_box=findBoxspeed(test_obtData1(:,2));
box_stat=checkBox(ref_speed_box,speed_box,variation_box);
%   Test metal presence
if box_stat==1 %Box presence
    resultant = find_resultant(test_obtData1);
    resultant=smooth(resultant);
    cvVal=findCV(resultant);
    [cvVal_all,avg_all]= checkInitialState(resultant,speed_box)
%   roller_noise = calcRollerEffect(test_obtData,roller_type,cvVal);
    load('roller_cond.mat');
    k=size(test_obtData1,1);
    roller_resultantAdjust=adjustRollerData(roller_resultant,k);
    roller_removed = filterRollerEffect(resultant,roller_resultantAdjust,roller_type);
    [metal_stat,flag_stat]= checkMetal(cvVal,ref_cv,cvVal_all,avg_all)
    largenoisemetal_stat=checkLargeNoiseMetal(cvVal,max_cv);
    displayStatus(box_stat,speed_box,cvVal,metal_stat,largenoisemetal_stat,roller_type);
%   plot_filtering(resultant,roller_noise,metal_stat);
else 
    displayNoBoxStatus(box_stat,speed_box,roller_type);
end
%  plot(1:size(resultant,1),[resultant aa])
% plot(1:size(resultant,1),resultant)
%  legend('Roller Affected','Roller Noise Filtered')
%  title('Roller Effect Filtering');
disp( mean(resultant));

% testPlot();


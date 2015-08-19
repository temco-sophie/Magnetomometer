function displayNoBoxStatus(obj_stat,speed_box,roller_type)

%Display object status
if obj_stat==-1; % Nothing present
    disp('NO BOX PRESENT');
end
if obj_stat==0; %Noise present
    disp('Other Noise PRESENT');
end

%Measure box speed..
disp(['The box speed is   = ' num2str(speed_box)]);

%Display roller type
if strcmp(roller_type,'conditional')==1
    disp('Roller-----Spins with box only')
end
if strcmp(roller_type,'always')==1
    disp('Roller-----Always Spinning')
end




for i=1:1
    test_obtData1=single_boxData{i};
    speed_box=findBoxspeed(test_obtData1(:,2));
    box_stat=checkBox(ref_speed_box,speed_box,variation_box);

    % Test metal presence
    if box_stat==1 %Box presence
        resultant = find_resultant(test_obtData1);
        cvVal=findCV(resultant);
%     roller_noise = calcRollerEffect(test_obtData,roller_type,cvVal);
%         load('roller_cond.mat');
%         k=size(test_obtData1,1);
%         roller_resultantAdjust=adjustRollerData(roller_resultant,k);
%         roller_removed = filterRollerEffect(resultant,roller_resultantAdjust,roller_type);
        metal_stat= checkMetal(cvVal,ref_cv,variation_cv);
        largenoisemetal_stat=checkLargeNoiseMetal(cvVal,max_cv);
        displayStatus(box_stat,speed_box,cvVal,metal_stat,largenoisemetal_stat,roller_type);
        %     plot_filtering(resultant,roller_noise,metal_stat);
    end
    % displayStatus(box_stat,speed_box,cvVal,metal_stat,largenoisemetal_stat,roller_type);
    plot(1:size(resultant,1),resultant);
    hold on;
end
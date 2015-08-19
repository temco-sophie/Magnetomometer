function single_boxData=abstractBox(test_obtData)
    timer_data=test_obtData(:,1);
    [start_pos] =find(timer_data==1);
    box_no=length(start_pos);
    for i=1:box_no
        if i==box_no
            single_boxData{i}=test_obtData(start_pos(i):end,:);
        else
            single_boxData{i}=test_obtData(start_pos(i):start_pos(i+1)-2,:);
        end        
    end
        
end
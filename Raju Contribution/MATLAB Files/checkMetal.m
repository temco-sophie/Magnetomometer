function [metal_stat,flag_stat]= checkMetal(cvVal,ref_cv,cvVal_all,avg_all)
% It checks the CV value and decides the metal presence.
% INPUT cvVal -> calculated cv value
%       ref_cv -> reference cv value for no metal case
%       variation_cv -> used for acceptable variation for tolerance
% OUTPUT metal_stat -> 1 BOX present and 0 Noise present

%     max_cv=ref_cv-variation_cv; %#codegen
    flag_initial=0;
    flag_last=0;

    if cvVal>=ref_cv && avg_all(2)> avg_all(1) 
        metal_stat=1; %BOX present
    %     disp('CONTAMINATED BOX--METAL DETECTED');
    else
        metal_stat=0; 
    %    disp('CLEAN BOX-- NO METAL PRESENT');
    end
    
    if cvVal_all(1)>cvVal_all(2) || avg_all(1)>avg_all(2)
        flag_initial=1;
    elseif avg_all(3)>avg_all(2)
        flag_last=1;
    end
    flag_stat =[flag_initial,flag_last];
end

int checkLargeNoiseMetal(cvVal,max_cv){
	
	int largenoisemetal_stat;
	if (cvVal>max_cv )
        largenoisemetal_stat=1; //Large metal presence
    else
        largenoisemetal_stat=0; //No large metal
        
    return largenoisemetal_stat;    
	
}

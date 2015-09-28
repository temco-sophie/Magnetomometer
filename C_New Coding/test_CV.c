double test_CV(double *resultant,int rows){
	double temp_mean=0.0,mean,sdev,cvVal,temp_var=0.0;
	int i;
	
	printf("\nTESRTTT\n")
	//Finding mean first
	for(i=0;i<rows;i++){  		
  			temp_mean+=*(resultant+i); 
		//printf("\nTest mean temp %lf",temp_mean);	 			  
	}
	mean=temp_mean/(double)rows;
	
	//Finding Standard Deviation
	for(i=0;i<rows;i++){
		temp_var+=(*(resultant+i)-mean)*(*(resultant+i)-mean);
	}
	sdev=sqrt(temp_var/(rows));
	
	//Finding Coefficient of variation
	cvVal=sdev/mean;
	
	return cvVal;	
}

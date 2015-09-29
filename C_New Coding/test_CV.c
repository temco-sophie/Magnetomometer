double test_CV(double *boxVal,int rows){
	double temp_mean=0.0,mean,sdev,cvVal,temp_var=0.0;
	int i;
	
	//printf("\nTESRTTT %lf\n",*(boxVal+1));
	//Finding mean first
	for(i=0;i<rows;i++){  		
  			temp_mean+=*(boxVal+i); 
		   // printf("\nTest mean temp %lf",temp_mean);	 			  
	}
	mean=temp_mean/(double)rows;
	//("\nMEAN INSIDE TEST %lf",mean);
	
	//Finding Standard Deviation
	for(i=0;i<rows;i++){
		temp_var+=(*(boxVal+i)-mean)*(*(boxVal+i)-mean);
	}
	sdev=sqrt(temp_var/(rows));
	
	//Finding Coefficient of variation
	cvVal=sdev/mean;
	
	return cvVal;	
//	return 500.00;
}

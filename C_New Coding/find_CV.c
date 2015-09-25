double find_CV(int *resultant,int rows){
	double temp_mean=0,mean,sdev,cvVal,temp_var=0;
	int i;
	//Finding mean first
	for(i=0;i<rows;i++){  		
  			temp_mean+=*(resultant+i); 			  
	}
	mean=temp_mean/rows;
	
	//Finding Standard Deviation
	for(i=0;i<rows;i++){
		temp_var+=(*(resultant+i)-mean)*(*(resultant+i)-mean);
	}
	sdev=sqrt(temp_var/(rows));
	
	//Finding Coefficient of variation
	cvVal=mean/sdev;
	
	return cvVal;	
}

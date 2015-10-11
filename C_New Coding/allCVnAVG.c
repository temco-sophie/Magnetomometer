double * allCVnAVG(double *resultant,int speed_box,int rows,int optoOnPos){
	double *result;
	result=malloc(sizeof(double)*6);
	double initialVal[optoOnPos],*boxVal,lastVal[optoOnPos],cvVal1,cvVal2,cvVal3,temp_mean=0.0,avg1,avg2,avg3;
	int i,length_box,j,p;
	boxVal=malloc(sizeof(double)*speed_box);
	
	for(i=0;i<optoOnPos;i++){
		initialVal[i]=*(resultant+i);
	}
	
	cvVal1=find_CV(initialVal,optoOnPos);
	
	boxVal=(resultant+optoOnPos);
	cvVal2=test_CV(boxVal,speed_box);
		
	j=0;
	for(i=(rows-optoOnPos-1);i<rows;i++){
		lastVal[j]=*(resultant+i+1);
		j++;				
	}
	
	cvVal3=find_CV(lastVal,optoOnPos);
		
	for(i=0;i<optoOnPos;i++){  		
  			temp_mean+=initialVal[i]; 			  
	}
	avg1=temp_mean/(double)optoOnPos;
	
	temp_mean=0.0;
	for(i=0;i<speed_box;i++){  
			  temp_mean+=*(boxVal+i);
	}
	avg2=temp_mean/(double)speed_box;
	
	temp_mean=0.0;
	for(i=0;i<optoOnPos;i++){  		
  			temp_mean+=lastVal[i]; 
	}
	avg3=temp_mean/(double)optoOnPos;
	
	*result=cvVal1;
	*(result+1)=cvVal2;
	*(result+2)=cvVal3;
	*(result+3)=avg1;
	*(result+4)=avg2;
	*(result+5)=avg3;
	
	return result;
    
}


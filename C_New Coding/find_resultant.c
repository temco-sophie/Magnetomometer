double * find_resultant(int *data,int rows){
	double *resultant,temp;
	int i,j;
	resultant=(double*)malloc(sizeof(double)*rows);
  	for(i=0;i<rows;i++){
  		temp=0.0;
  		for(j=2;j<col;j++)
  			temp+=(*(data+i*col+j))*(*(data+i*col+j)); 
			*(resultant+i)=sqrt(temp);		
	}
	return resultant;
}


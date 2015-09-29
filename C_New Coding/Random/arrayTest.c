 
 #include <stdio.h>

int* add(int *data,int rows)
{
    int i, j,tempvar;

    
    for (i = 0; i < rows; i++)
    {
    	tempvar=0;
		for (j = 0; j < 3; j++)
     	{
     	// *(data + 3 * i + j) += *(data + 3 * i + j);   
		  tempvar += *(data + 3 * i + j); 
		  printf("\nTempvar %d",tempvar);
	 	}
	 	printf("\nOUt Tempvar %d",tempvar);
	   *(data + 3*i ) = tempvar;
	 	 	
	} 
		  
}

/* main function to call above defined function */
int main ()
{
   /* a pointer to an int */
   int *p;
   int i,j,length;
   int data[][3] = {{1, 2, 3}, {4, 5, 6}};
   int temp[][3]={};
        
      
   length=sizeof(data)/sizeof(data[0]);
      
   printf("Test Length %d\n",length);
   
   for (i=0;i<length;i++)
   	for(j=0;j<3;j++)
   		temp[i][j]=data[i][j];
   
    printf("\nTemp Printing\n");
   for ( i = 0; i < length; i++ )
   {
   	printf("\n");
   	for (j=0;j<3;j++)
    	printf("\t %d",data[i][j]);
   }
   		

  
   printf("\nBefore passing\n");
   for ( i = 0; i < length; i++ )
   {
   	printf("\n");
   	for (j=0;j<3;j++)
    	printf("\t %d",data[i][j]);
   }
   
   
    add(temp,length);
    printf("\nAfer passing\n");
    for ( i = 0; i < length; i++ )
   {
   	printf("\n");
   	for (j=0;j<3;j++)
    	printf("\t %d",temp[i][j]);    	
   } 
   
   p=temp+1;
   printf("\n Printing P \n") ;
    
 // for(i=0;i<length;i++)
  printf("\n%d",*p);
   

   return 0;
}


#include <stdio.h>
#define COL 3
int * add(int *data,int rows,int r[2])
{
  	int result[2];
  	int i,j;
  	for(i=0;i<rows;i++){
  		result[i]=0;
  		for(j=0;j<COL;j++)
  			result[i]+=*(data+i*COL+j);
  		r[i]=result[i];
	  }
  	return result;
}

/* main function to call above defined function */
int main ()
{
   /* a pointer to an int */
   int *p;
   int i,j,length;
   int data[][3] = {{1, 2, 3}, {4, 5, 6}};
   int result[2]; 
      
   length=sizeof(data)/sizeof(data[0]);
   p=add(data,length,result);
   printf("%d",*(p));
   printf(" %d",result[0]);
   
    

   return 0;
}


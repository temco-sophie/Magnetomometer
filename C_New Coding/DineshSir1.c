#include <stdio.h>
#define COL 3
void add(int *data,int rows,int r[])
{
  	//int result[2];
  	int i,j;
  	for(i=0;i<rows;i++){
  		r[i]=0;
  		for(j=0;j<COL;j++)
  			r[i]+=*(data+i*COL+j);
  		//r[i]=result[i];
	  }
  	//return result;
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
   add(data,length,result);
   //printf("%d",*(p));
   printf(" %d",result[1]);
   
    

   return 0;
}


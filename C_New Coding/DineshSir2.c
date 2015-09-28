#include <stdio.h>
#include <math.h>
#define COL 8
double total(int *rdata,int rows){
	int result=0;
	int i;
	printf("Raju %d\n",*(rdata+1));
	for(i=0;i<rows;i++){  		
  			result+=*(rdata+i);
			  printf("\nTest %d",result);						  
	}
	
	double r=sqrt(result);
	return r;
}
int * add(int *data,int rows)
{
  	int *result;
  	result=malloc(sizeof(int)*rows);
  	int i,j;
  	for(i=0;i<rows;i++){
  		*(result+i)=0;
  		for(j=0;j<COL;j++)
  			*(result+i)+=*(data+i*COL+j);
  		
	}
	/*
	*(result+0)=111;
	*(result+1)=222;
	*/
  	return result;
}

/* main function to call above defined function */
int main ()
{
   /* a pointer to an int */
   int *p;
   double sumval;
   int i,j,length;
   int data[][COL] = {
	{1, 0, 289, 242, -151, -43, 20, 437},
	{2, 0, 289,	242, -151, -43,	20,	437},
	{3,	0, 277,	221,	-124,	-43,	20,	437},
	{4,	0,	277,	221,	-124,	-81,	14,	430},
	{5,	0,	277,	221,	-124,	-81,	14,	430},
	{6,	0,	284,	213,	-143,	-37,	14,	448},
	{7,	0,	284,	213,	-143,	-37,	14,	448},
	{8,	0,	302,	229,	-113,	-61,	-60,356},
	{9,	0,	263,	165,	-123,	-61,	-60,356},
	{10,0,	263,	165,	-123,	-141,	-102,401}
	};         
   length=sizeof(data)/sizeof(data[0]);
   p=add(data,length);
   for(i=0;i<length;i++)
   printf("%d\n",*(p+i));
   sumval=total(p,length);
   printf("\nSum=%lf\n",sumval);
   printf(" %d",sizeof(char));
   
    

   return 0;
}


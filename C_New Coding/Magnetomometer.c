#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define col 8
#include "findBoxSpeed.c"
#include "checkBox.c"
#include "find_resultant.c"
#include "find_CV.c"


int findBoxSpeed();
int checkBox();
double * find_resultant();
double find_CV();

int main()
{
	
	
	int data[][col] = {
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
	int rows,speed_box,box_stat,i,j;
	int ref_speed_box=10; //Set for test purpose: The assumption is desired box is active in opto range for 3 second 
    int variation_box=5;
    double *resultant,cvVal;
   
   	rows=sizeof(data)/sizeof(data[0]);
  	
  	printf("Magnetomometer Project Test\n");  
	speed_box=findBoxSpeed(data,rows);
	box_stat=checkBox(ref_speed_box,speed_box,variation_box);
	resultant=find_resultant(data,rows);
	
	for(i=0;i<rows;i++){
		printf("\n Resultant %lf",*(resultant+i));
	}
	
	cvVal=find_CV(resultant,rows);
	
	printf("\n CV= %lf",cvVal);
		
	return 1;
}


#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "findBoxSpeed.c"
#include "checkBox.c"

int findBoxSpeed();
int checkBox();
int find_resultant();

int main()
{
	
	int data[10][8] = {
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
	int length,speed_box,box_stat,i;
	int ref_speed_box=10; //Set for test purpose: The assumption is desired box is active in opto range for 3 second 
    int variation_box=5;
    
   
  	//length=sizeof(data)/sizeof(data[0]);
  	length=10;
  	int *resultant;
  	printf("Magnetomometer Project Test\n");
	speed_box=findBoxSpeed(data,length);
	box_stat=checkBox(ref_speed_box,speed_box,variation_box);
	resultant=find_resultant(data,length);
	
	for (i=0;i<length-1;++i)
	 	printf("\nResultant %d",resultant[i]);
	
//	for (i = 0; i < length-1; i++)
	//	printf("Resultant []= %f \n",*(resultant));

	return 1;
}

//double find_resultant(double data[][8],int length,double resultant[length])
int (*(find_resultant)(int data[][8], int length))[8]
{
	printf("\nResultant %f",resultant[1]);
	int i;
	for (i=0;i<length-1;++i)
	resultant[i]=data[i][2];
	return resultant;
	 
}

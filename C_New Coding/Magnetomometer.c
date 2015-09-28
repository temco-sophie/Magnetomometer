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
double checkInitialStateCV();
double test_CV();

int main()
{
	
	
	int data[][col] = {
		{   1,  0,  289,   242,  -151,   -43,    20,   437},    
		{   2,  0,  289,   242,  -151,   -43,    20,   437},    
		{   3,  0,  277,   221,  -124,   -43,    20,   437},    
		{   4,  0,  277,   221,  -124,   -81,    14,   430},    
		{   5,  0,  277,   221,  -124,   -81,    14,   430},    
		{   6,  0,  284,   213,  -143,   -37,    14,   448},    
		{   7,  0,  284,   213,  -143,   -37,    14,   448},    
		{   8,  0,  302,   229,  -113,   -61,   -60,   356},    
		{   9,  0,  263,   165,  -123,   -61,   -60,   356},    
		{  10,  0,  263,   165,  -123,  -141,  -102,   401},    
		{  11,  0,  263,   165,  -123,  -141,  -102,   401},    
		{  12,  0,  305,   254,  -101,  -141,  -102,   401},    
		{  13,  0,  305,   254,  -101,   -48,   -87,   339},    
		{  14,  0,  305,   254,  -101,   -48,   -87,   339},    
		{  15,  0,  339,   225,  -146,   -84,     4,   414},    
		{  16,  0,  339,   225,  -146,   -84,     4,   414},    
		{  17,  0,  339,   225,  -146,   -84,     4,   414},    
		{  18,  0,  238,   218,   -49,   -82,   -99,   407},    
		{  19,  1,  238,   218,   -49,   -82,   -99,   407},    
		{  20,  1,  238,   218,   -49,   -52,   -21,   350},    
		{  21,  1,  356,   225,  -136,   -52,   -21,   350},    
		{  22,  1,  356,   225,  -136,   -52,   -21,   350},    
		{  23,  1,  301,   169,   -78,  -140,   -61,   414},    
		{  24,  1,  301,   169,   -78,  -140,   -61,   414},    
		{  25,  1,  301,   169,   -78,  -140,   -61,   414},    
		{  26,  1,  337,   278,  -108,   -51,   -68,   341},    
		{  27,  1,  337,   278,  -108,   -51,   -68,   341},    
		{  28,  1,  337,   278,  -108,  -143,   -16,   402},    
		{  29,  1,  297,   185,  -100,  -143,   -16,   402},    
		{  30,  1,  297,   185,  -100,  -143,   -16,   402},    
		{  31,  1,  297,   185,  -100,   -28,   -50,   382},    
		{  32,  1,  311,   206,  -115,   -28,   -50,   382},    
		{  33,  1,  311,   206,  -115,  -108,   -52,   370},    
		{  34,  1,  311,   206,  -115,  -108,   -52,   370},    
		{  35,  1,  328,   199,  -142,  -108,   -52,   370},    
		{  36,  1,  328,   199,  -142,   -69,   -42,   382},    
		{  37,  1,  328,   199,  -142,   -69,   -42,   382},    
		{  38,  1,  294,   232,  -134,  -110,   -36,   379},    
		{  39,  1,  294,   232,  -134,  -110,   -36,   379},    
		{  40,  1,  294,   232,  -134,  -110,   -36,   379},    
		{  41,  1,  285,   225,  -111,   -70,   -54,   385},    
		{  42,  1,  285,   225,  -111,   -70,   -54,   385},    
		{  43,  1,  285,   225,  -111,  -111,   -44,   379},    
		{  44,  1,  304,   213,  -117,  -111,   -44,   379},    
		{  45,  1,  304,   213,  -117,  -111,   -44,   379},    
		{  46,  1,  304,   213,  -117,   -86,   -63,   381},    
		{  47,  1,  328,   216,  -147,   -86,   -63,   381},    
		{  48,  1,  328,   216,  -147,  -103,   -39,   374},    
		{  49,  1,  314,   221,  -149,  -103,   -39,   374},    
		{  50,  1,  314,   221,  -149,  -103,   -39,   374},    
		{  51,  1,  314,   221,  -149,   -95,   -51,   374},    
		{  52,  1,  303,   228,  -127,   -95,   -51,   374},    
		{  53,  1,  303,   228,  -127,   -95,   -51,   374},    
		{  54,  1,  303,   228,  -127,   -84,   -32,   385},    
		{  55,  1,  306,   207,  -118,   -84,   -32,   385},    
		{  56,  1,  306,   207,  -118,  -108,   -35,   371},    
		{  57,  1,  306,   207,  -118,  -108,   -35,   371},    
		{  58,  1,  334,   216,  -134,  -108,   -35,   371},    
		{  59,  1,  334,   216,  -134,   -75,   -44,   389},    
		{  60,  1,  334,   216,  -134,   -75,   -44,   389},    
		{  61,  1,  328,   229,  -133,  -118,   -38,   377},    
		{  62,  1,  328,   229,  -133,  -118,   -38,   377},    
		{  63,  1,  328,   229,  -133,  -118,   -38,   377},    
		{  64,  1,  301,   235,  -104,   -83,   -42,   392},    
		{  65,  1,  301,   235,  -104,   -83,   -42,   392},    
		{  66,  1,  301,   235,  -104,  -112,   -48,   379},    
		{  67,  1,  301,   232,  -106,  -112,   -48,   379},    
		{  68,  1,  301,   232,  -106,  -112,   -48,   379},    
		{  69,  1,  301,   232,  -106,   -75,   -42,   380},    
		{  70,  1,  335,   216,  -131,   -75,   -42,   380},    
		{  71,  1,  335,   216,  -131,  -105,   -32,   372},    
		{  72,  1,  335,   216,  -131,  -105,   -32,   372},    
		{  73,  1,  335,   224,  -148,  -105,   -32,   372},    
		{  74,  1,  335,   224,  -148,   -76,   -43,   386},    
		{  75,  1,  335,   224,  -148,   -76,   -43,   386},    
		{  76,  1,  305,   236,  -126,  -101,   -16,   387},    
		{  77,  1,  305,   236,  -126,  -101,   -16,   387},    
		{  78,  1,  305,   236,  -126,  -101,   -16,   387},    
		{  79,  1,  293,   237,  -110,   -83,   -31,   381},    
		{  80,  1,  293,   237,  -110,   -83,   -31,   381},    
		{  81,  1,  320,   228,  -130,   -98,   -10,   391},    
		{  82,  1,  320,   228,  -130,   -98,   -10,   391},    
		{  83,  1,  320,   228,  -130,   -98,   -10,   391},    
		{  84,  1,  335,   232,  -132,  -115,   -33,   382},    
		{  85,  1,  335,   232,  -132,  -115,   -33,   382},    
		{  86,  1,  335,   232,  -132,   -79,   -31,   396},    
		{  87,  1,  303,   248,  -146,   -79,   -31,   396},    
		{  88,  1,  303,   248,  -146,   -79,   -31,   396},    
		{  89,  1,  303,   248,  -146,  -112,   -37,   383},    
		{  90,  1,  295,   243,  -126,  -112,   -37,   383},    
		{  91,  1,  295,   243,  -126,  -112,   -37,   383},    
		{  92,  1,  295,   243,  -126,   -69,   -32,   384},    
		{  93,  1,  328,   227,  -145,   -69,   -32,   384},    
		{  94,  1,  328,   227,  -145,   -95,   -29,   380},    
		{  95,  1,  328,   227,  -145,   -95,   -29,   380},    
		{  96,  1,  334,   228,  -158,   -95,   -29,   380},    
		{  97,  1,  334,   228,  -158,   -65,   -25,   395},    
		{  98,  1,  334,   228,  -158,   -65,   -25,   395},    
		{  99,  1,  309,   250,  -144,   -95,   -20,   381},    
		{ 100,  1,  309,   250,  -144,   -95,   -20,   381},    
		{ 101,  1,  309,   250,  -144,   -95,   -20,   381},    
		{ 102,  1,  287,   236,  -123,   -77,   -41,   400},    
		{ 103,  1,  287,   236,  -123,   -77,   -41,   400},    
		{ 104,  1,  316,   231,  -122,  -101,    -7,   390},    
		{ 105,  1,  316,   231,  -122,  -101,    -7,   390},    
		{ 106,  1,  316,   231,  -122,  -101,    -7,   390},    
		{ 107,  1,  344,   224,  -153,   -84,   -28,   392},    
		{ 108,  1,  344,   224,  -153,   -84,   -28,   392},    
		{ 109,  1,  344,   224,  -153,   -81,   -16,   390},    
		{ 110,  1,  309,   252,  -142,   -81,   -16,   390},    
		{ 111,  1,  309,   252,  -142,   -81,   -16,   390},    
		{ 112,  1,  309,   252,  -142,   -96,   -25,   384},    
		{ 113,  1,  315,   242,  -128,   -96,   -25,   384},    
		{ 114,  1,  315,   242,  -128,   -63,    -8,   402},    
		{ 115,  1,  315,   242,  -128,   -63,    -8,   402},    
		{ 116,  1,  305,   225,  -111,   -63,    -8,   402},    
		{ 117,  1,  305,   225,  -111,  -103,   -12,   388},    
		{ 118,  1,  305,   225,  -111,  -103,   -12,   388},    
		{ 119,  1,  334,   218,  -138,   -54,    -8,   400},    
		{ 120,  1,  334,   218,  -138,   -54,    -8,   400},    
		{ 121,  1,  334,   218,  -138,   -54,    -8,   400},    
		{ 122,  1,  311,   257,  -138,  -100,   -23,   406},    
		{ 123,  1,  311,   257,  -138,  -100,   -23,   406},    
		{ 124,  1,  311,   257,  -138,   -62,    -6,   405},    
		{ 125,  1,  292,   256,  -115,   -62,    -6,   405},    
		{ 126,  1,  292,   256,  -115,   -62,    -6,   405},    
		{ 127,  1,  292,   256,  -115,   -89,     0,   399},    
		{ 128,  1,  294,   235,  -122,   -89,     0,   399},    
		{ 129,  1,  294,   235,  -122,   -89,     0,   399},    
		{ 130,  1,  325,   239,  -147,   -60,   -20,   405},    
		{ 131,  1,  325,   239,  -147,   -60,   -20,   405},    
		{ 132,  1,  325,   239,  -147,   -82,     5,   394},    
		{ 133,  1,  329,   241,  -159,   -82,     5,   394},    
		{ 134,  1,  329,   241,  -159,   -82,     5,   394},    
		{ 135,  1,  329,   241,  -159,   -53,    -9,   398},    
		{ 136,  1,  301,   253,  -132,   -53,    -9,   398},    
		{ 137,  1,  301,   253,  -132,   -67,    12,   409},    
		{ 138,  1,  301,   253,  -132,   -67,    12,   409},    
		{ 139,  1,  290,   230,  -128,   -67,    12,   409},    
		{ 140,  0,  290,   230,  -128,   -91,    -1,   407},    
		{ 141,  0,  290,   230,  -128,   -91,    -1,   407},    
		{ 142,  0,  306,   244,  -157,   -51,   -18,   428},    
		{ 143,  0,  306,   244,  -157,   -51,   -18,   428},    
		{ 144,  0,  306,   244,  -157,   -51,   -18,   428},    
		{ 145,  0,  322,   245,  -159,   -82,    -2,   400},    
		{ 146,  0,  322,   245,  -159,   -82,    -2,   400},    
		{ 147,  0,  322,   245,  -159,   -42,    -2,   421},    
		{ 148,  0,  292,   258,  -154,   -42,    -2,   421},    
		{ 149,  0,  292,   258,  -154,   -42,    -2,   421},    
		{ 150,  0,  292,   258,  -154,   -73,    -9,   409},    
		{ 151,  0,  284,   260,  -136,   -73,    -9,   409},    
		{ 152,  0,  284,   260,  -136,   -35,     0,   414},    
		{ 153,  0,  284,   260,  -136,   -35,     0,   414},    
		{ 154,  0,  315,   235,  -158,   -35,     0,   414},    
		{ 155,  0,  315,   235,  -158,   -62,     8,   406},    
		{ 156,  0,  315,   235,  -158,   -62,     8,   406},    
		{ 157,  0,  324,   235,  -167,   -62,     8,   406},    
		{ 158,  0,  324,   235,  -167,   -40,    -3,   412},    
		{ 159,  0,  324,   235,  -167,   -40,    -3,   412},    
		{ 160,  0,  293,   249,  -158,   -47,    24,   410},    
		{ 161,  0,  293,   249,  -158,   -47,    24,   410},    
		{ 162,  0,  272,   240,  -136,   -47,    24,   410},    
		{ 163,  0,  272,   240,  -136,   -59,     7,   420},    
		{ 164,  0,  272,   240,  -136,   -59,     7,   420},    
		{ 165,  0,  301,   237,  -144,   -49,    15,   422},    
		{ 166,  0,  301,   237,  -144,   -49,    15,   422},    
		{ 167,  0,  301,   237,  -144,   -49,    15,   422},    
		{ 168,  0,  332,   229,  -158,   -72,    13,   417},    
		{ 169,  0,  332,   229,  -158,   -72,    13,   417},    
		{ 170,  0,  332,   229,  -158,   -40,     2,   428},    
		{ 171,  0,  304,   262,  -159,   -40,     2,   428},    
		{ 172,  0,  304,   262,  -159,   -40,     2,   428},    
		{ 173,  0,  304,   262,  -159,   -66,     2,   419},    
		{ 174,  0,  286,   255,  -152,   -66,     2,   419},    
		{ 175,  0,  286,   255,  -152,   -18,     2,   430},    
		{ 176,  0,  286,   255,  -152,   -18,     2,   430},    
		{ 177,  0,  279,   241,  -131,   -18,     2,   430},    
		{ 178,  0,  279,   241,  -131,   -68,     6,   413},    
		{ 179,  0,  279,   241,  -131,   -68,     6,   413},    
		{ 180,  0,  311,   214,  -156,   -26,     8,   428},    
		{ 181,  0,  311,   214,  -156,   -26,     8,   428},    
		{ 182,  0,  311,   214,  -156,   -26,     8,   428},    
		{ 183,  0,  300,   248,  -161,   -56,     0,   428},    
		{ 184,  0,  300,   248,  -161,   -56,     0,   428},    
		{ 185,  0,  300,   248,  -161,   -56,     0,   428},    
		{ 186,  0,  285,   250,  -138,   -36,    -3,   429},    
		{ 187,  0,  285,   250,  -138,   -36,    -3,   429},    
		{ 188,  0,  281,   236,  -127,   -65,    15,   428},    
		{ 189,  0,  281,   236,  -127,   -65,    15,   428},    
	};
	int rows,speed_box,box_stat,i,j;
	int ref_speed_box=10; //Set for test purpose: The assumption is desired box is active in opto range for 3 second 
    int variation_box=5;
    double *resultant,cvVal,cvVal_all;
   
   	rows=sizeof(data)/sizeof(data[0]);
  	
  	printf("Magnetomometer Project Test\n");  
	speed_box=findBoxSpeed(data,rows);
	box_stat=checkBox(ref_speed_box,speed_box,variation_box);
	resultant=find_resultant(data,rows);
	/*for(i=0;i<rows;i++){
		printf("\n %lf",*(resultant+i));
	}*/
	cvVal=find_CV(resultant,rows);	
	cvVal_all= checkInitialStateCV(resultant,speed_box,rows);
	printf("\n CV= %lf",cvVal);
		
	return 1;
}

double checkInitialStateCV(double *resultant,int speed_box,int rows){
	/*initialVal=resultant(1:50,:);
    boxVal=resultant(50:50+speed_box,:);
    lastVal=resultant(50+speed_box:end,:);
    cvVal1=findCV(initialVal);
    cvVal2=findCV(boxVal);
    cvVal3=findCV(lastVal);
    cvVal_all=[cvVal1 cvVal2 cvVal3];
    avg1=mean(initialVal);
    avg2=mean(boxVal);
    avg3=mean(lastVal);
    avg_all=[avg1 avg2 avg3]; */
    double initialVal[50];
	double *boxVal;
	double lastVal[50];
	double cvVal1,cvVal2;
	int i,length_box,j;
	
	for(i=0;i<50;i++){
		initialVal[i]=*(resultant+i);
	//	printf("\n Initial [%d] %lf",i,initialVal[i]);
	}
	cvVal1=find_CV(initialVal,50);
	printf("\naa%lf",cvVal1);
	

	boxVal=(resultant+50);
	cvVal2=test_CV(boxVal,speed_box);
	printf("\naa1 %lf",cvVal2);
	
	
/*	printf("\n Initial [%d] %lf",i,*(boxVal));
	for(i=50;i<(rows-50);i++){
		j=i-50;
	//	boxVal=(resultant+i);
		printf("\n Initial [%d] %lf",i+1,*(boxVal+j));
	}
	
	/*for(i=(rows-100);i<rows;i++){
		lastVal[i-rows]=*(resultant+i);
	}	
	
	/*length_box=rows-100;
	cvVal1=find_CV(initialVal,50);
	printf("\ncvVal1 = %lf",cvVal1)	;
	cvVal2=find_CV(boxVal,length_box);
	
	printf("\ncvVal2 = %lf",cvVal2)	; */
    
}



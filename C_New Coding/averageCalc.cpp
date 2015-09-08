
#include <stdio.h> 
/* function declaration */
double getAverage(int arr[]);
int main ()
{
   /* an int array with 5 elements */
   int a[] = {1000, 2, 3, 17, 50,1000,123};
   double avg;
   int size;
   size = sizeof(a)/sizeof(a[0]);
   printf(" SIze2 %d\n",sizeof(a));   
   /* pass pointer to the array as an argument */
   avg = getAverage( a) ;
 
   /* output the returned value */
   printf( "Average value is: %f ", avg );
    
   return 0;
}
double getAverage(int arr[])
{
  int    i;
  double avg;
  double sum;
  int size;
  size = sizeof(arr)/sizeof(arr[0]);
  printf(" SIze1 %d\n",sizeof(arr));

  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
  }

 printf(" SIze %d\n",sizeof(arr));
  avg = sum / size;

  return avg;
}

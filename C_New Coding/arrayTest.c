const int n = 3;
#include <stdio.h>
#include "print.c" 
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr, 3);
    int i, j;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
           	printf("\nInside main %d ", arr[i][j]);
        
	return 0;
}

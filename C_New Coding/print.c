int print(int arr[][n], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
      {
      	printf("Inside function %d \n", arr[i][j]);
        arr[i][j]=2*arr[i][j];
	  }
	  return arr;
        
}

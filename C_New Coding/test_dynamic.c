 void func(int** array, int rows, int cols)
    {
      int i, j;

        for(i=0;i<rows;i++)
      {
	  
      	for (j=0;j<cols;j++)
      	{
      		array[i][j]=array[i][j];
		  }		  
	}
    }

    int main()
    {
      int rows, cols, i,j;
      int *x;
      
      	int data[][8] = {
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

      /* obtain values for rows & cols */
      rows=sizeof(data)/sizeof(data[0]);
      cols=8;
      
      printf("Rows= %d\n",rows);

      /* allocate the array */
      x = malloc(rows * sizeof *x);
       /* use the array */
      func(data,x, rows, cols);
      
      for(i=0;i<rows;i++)
      
      
     

   
      
  }

    

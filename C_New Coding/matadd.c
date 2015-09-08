#include <stdio.h>
int (*(Matrix_sum)(int matrix1[][3], int matrix2[][3])){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix1;
}
int main(){
    int x[3][3], y[3][3];
    int (*a)[3]; //pointer to an array
    int i,j;
    printf("Enter the matrix1: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%d",&x[i][j]);
        }
    }
    printf("Enter the matrix2: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%d",&y[i][j]);
        }
    }
    a = Matrix_sum(x,y); //asigning
    printf("The sum of the matrix is: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d",a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}


#include <stdio.h>

#include <stdlib.h>

int* test(int size, int x){
    int *factorFunction = (int *) malloc(sizeof(int) * size);    
    if( factorFunction != NULL ) //makes sure malloc was successful
    {
        factorFunction[0] = 5 + x;
        factorFunction[1] = 7 + x;
        factorFunction[2] = 9 + x; //this line won't work because your array is only 2 ints long

    }
return factorFunction;
}

int main(void){
    int *factors;
    factors = test(2, 3);
    printf("%d", factors[1]);
    //just remember to free the variable back to the heap when you're done
    free(factors);
    return 0;
}

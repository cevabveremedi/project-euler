#include <stdio.h>
#include <stdlib.h>

int isAbundant(int num);

int main (void) {
    int i, j, total = 0;
    
    // find the total number of abundants and make an array of that size.
    for(i = 2; i < 28124; i++) {
        if(isAbundant(i)) total ++;
    }

    int* abundantNumbers = malloc(sizeof(int) * total);

    // add the abundant numbers to the array.
    j = 0;
    for(i = 2; i < 28124; i++) {
        if(isAbundant(i)) abundantNumbers[j++] = i;
    }

    // create a new array to check if the index is a sum of two abundant numbers.
    int array[28124] = {0};

    // if abundant-number1 + abundant-number2 is in the range of the array size, check that index.
    for(i = 0; i < total; i++) {
        int num1 = abundantNumbers[i];
        for(j = 0; j < total; j++) {
            int num2 = abundantNumbers[j];
            if(num1 + num2 < 28124) array[num1 + num2] = 1;
        }
    }

    // calculate the sum of the numbers which are not a sum of two abundant numbers
    total = 0;

    for(i = 0; i < 28124; i++) {
        if(!array[i]) total += i;
    }

    printf("total: %d \n", total);

    free(abundantNumbers);
}

int isAbundant(int num) {
    int sum = 1;

    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) sum += i;
    }

    return sum > num ? 1 : 0;
}
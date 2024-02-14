// Consider following C code. Assume unsigned long int type length is 64 bits.
// Determine the value returned when we call fun with the input 2^40. 

#include <stdio.h>

unsigned long int fun(unsigned long int n){
    unsigned long int i, j = 0, sum = 0;
    for(i = n; i > 1; i = i/2){
        j++;
    }
    for(; j > 1; j = j/2){
        sum++;
    }

    return sum;
}

int main(){
    unsigned long int powerOf2_40 = 1ULL << 40; // Calculate 2 to the power of 40
    unsigned long int sol = fun(powerOf2_40); // Pass it as parameter to fun
    printf("Solution: %lu\n", sol);
    return 0;
}

// OUTPUT

// Solution: 5

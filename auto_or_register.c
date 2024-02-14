#include <stdio.h>

void fun(){
    int x = 1;
    x = x + 2;
    printf("%d", x);
    printf("\n");
}

void main(){
    int i;
    for(i = 1; i < 5; i++){
        fun();
    }
}

// For each for loop, x is created and destroyed again and again as it is automatic variable

// OUTPUT - 

// 3
// 3
// 3
// 3


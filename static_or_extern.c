#include <stdio.h>

void fun(){
    static int x = 1;
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

// Here, since x is static variable, it is created once and  retains its value throughout the program execution. 
// During second iteration of for loop, Line number 4 wont be considered 

// OUTPUT - 

// 3
// 5
// 7
// 9
#include <stdio.h>

unsigned int foo(unsigned int n, unsigned int r){
    if(n > 0){
        return((n%r) + foo(n/r, r));
    }
    else{
        return 0;
    }
}

int main(){
    unsigned int sol = foo(513, 2);
    printf("%d", sol);
}

// Output - 2
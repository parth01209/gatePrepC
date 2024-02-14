#include <stdio.h>

int fun(int x){
    if(x == 0){
        return 1;
    }
    else{
        fun(x-1);
        printf("x=%d",x);
    }
}

int main(){
    int sol = fun(4);
    printf("%d", sol);
    return 0;
}

// OUTPUT - 1 2 3 4
// Logic -
// for fun(4), else condition executes and control transfers to fun(3), then to fun(2) and then to fun(1) and fun(0)
// Now if condition is executed control is trnfered back to next line i.e printf
// so value of x are printed from 1 to 4 
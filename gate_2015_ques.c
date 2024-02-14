// Consider following C program.
// Determine number of times printf() is executed 

#include <stdio.h>

int main(){
    int i, j, k = 0;
    j = 2 * 3 / 4 + 2.0 / 5 + 8 / 5; // j = 1 + 0.4 + 1 = 2 (C language oprator precedance)
    k- = --j; // k = k - --j => k = 0 - 1 = -1
    for(i = 0; i < 5; i++){
        switch(i + k){
            case 1:
            case 2: printf("\n%d", i + k);
            case 3: printf("\n%d", i + k);
            default: printf("\n%d", i + k);

        }
    }
    return 0;
}
//             i+k             Total count
// i = 0       0 + -1 = -1     default printf() - 1
// i = 1       1 + -1 = 0      default printf() - 2
// i = 2       2 + -1 = 1      case 2, case 3, defalut printf() - 5
// i = 3       3 + -1 = 2      case 2, case 3, defalut printf() - 8
// i = 4       4 + -1 = 3      case 3, defalut printf() - 10
 

// Output - printf() gets executed 10 times 
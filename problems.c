#include <stdio.h>

void main()
{
    int i = 10, j = 5, k, l;
    k = i++ - ++j;
    l = --j + i--;
    
    printf("%d,%d,%d,%d", i, j, k, l);
    printf("\n");
    

    
}
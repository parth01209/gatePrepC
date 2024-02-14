#include <stdio.h>

void main()
{
    int a = 7, b = -3, c = 9;
    
    a = a++ + ++b + c--;
    b = b-- - --a - --c;
    c = c++ + ++a + --b;
    printf("%d,%d,%d", a,b,c);
    

    
}
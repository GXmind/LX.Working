#include<stdio.h>
int hanshu( int n )
{
    int JS = 0;
 
    while ( n != 0 )
    {
        JS+= n & 1;
        n >>= 1;
    }
    return JS;
}
 
int main()
{
    int n;
    while ( scanf("%d", &n) != EOF ) 
    {
        printf("%d\n", hanshu( n ));
    }
    return 0;
}
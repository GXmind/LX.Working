#include <stdio.h>
int hanshu(int a,int b,int c)
{
    int t;
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    if(a>c)
    {
        t=a;
        a=c;
        c=t;
    }
    if(b>c)
    {
        t=b;
        b=c;
        c=t;
    }
    printf("%d,%d,%d",a,b,c);
}
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        hanshu(a,b,c);
    }
}
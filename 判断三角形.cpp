#include<bits/stdc++.h>
using namespace std;
void fun(int a,int b,int c)
{
    if(a+b>c&&b+c>a&&a+c>b)
    {
        if(a==b||b==c||a==c)
        {
            printf("a=%d,b=%d,c=%d\n",a,b,c);
            printf("The shape:2\n");
        }
        else if(a==b&&b==c)
        {
            printf("a=%d,b=%d,c=%d\n",a,b,c);
            printf("The shape:3\n");

        }
        else
        { 
            printf("a=%d,b=%d,c=%d\n",a,b,c);
            printf("The shape:1\n");

        }
    }
    else
    {
        printf("a=%d,b=%d,c=%d\n",a,b,c);
        printf("The shape:0\n");

    }
    
};
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    fun(a,b,c);

    return 0;
}
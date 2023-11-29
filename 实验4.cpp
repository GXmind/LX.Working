#include<bits/stdc++.h>
using namespace std;
void funs(int a)
{
    int T=0;
    for(int i=1;i<=a;i++)
    {
        int num=T;
        while(num--)
        {
            int x=1;
            printf("%4d",x);
        }
        for(int j=1;j<=a-T;j++)
        {
            printf("%4d",j);
        }
        printf("\n");
        T++;
    }
}
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        funs(a);
    }
    return 0;
}
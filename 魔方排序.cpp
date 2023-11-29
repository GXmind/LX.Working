#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[20][20]={0};
    scanf("%d",&n); 
    int i,j,k,m;
    i=1;
    j=n/2+1;
    a[i][j]=1;
    for(k=2;k<=n*n;k++)
    {
            i=i-1;
            j=j+1;
        if((i<=0)&&(j<=n))
        {
            i=n;
        }
        if((i<=0)&&(j>n))
        {
            i=i+2;
            j=j-1;
        }
        if(j>n)
        {
            j=1;
        }
        if(a[i][j]==0)
        {
            a[i][j]=k;
        }   
        else
        {
            i=i+2;
            j=j-1;
            a[i][j]=k;
        }
    }
 for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int hanshu(int a,int b,int c,int d)
{
    int min=a;
    if(min>b)
    min=b;
    if(min>c)
    min=c;
    if(min>d)
    min=d;
    return min;
}
int main()
{
    int n;
    int i,j,min,s;
    while(~scanf("%d",&n))
    {
      s=2*n-1;
      for(i=1;i<=s;i++)
      {
        for(j=1;j<=s;j++)
        {
            min=hanshu(i,j,s+1-i,s+1-j);
            printf("%d",min);
        }
        printf("\n");
      }  

    }
}
#include <stdio.h>
int main()
{
    int a;
    float b,c,d,e;
    float sum[1000];
    while(~scanf("%d",&a))
    {
        for(int i=0;i<a;i++)
        {
            scanf("%f%f%f%f",&b,&c,&d,&e);
            sum[i]=b+c+d+e;
        }
        for(int i=0;i<a;i++)
        {
            printf("%.2lf\n",sum[i]);
        }

        
        
        
    }
}
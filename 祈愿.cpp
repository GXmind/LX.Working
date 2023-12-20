#include <stdio.h>
int main()
{
    int t;
    int n;
    int a[1000];
    while(t--)
    {
        int ts = 0;
        int ave;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            /*如果出现90抽*/
            if(a[i] == 90)
            {ts = 0;}
        }
        ave = sum/n;
        if(ts == 0)
        {
            if(ave>=1 && ave<=30)
            printf("ChaoJiOuHuang/n");
            if(ave>30 && ave<=60)
            printf("OuHuang/n");
            if(ave>60 && ave<=80)
            printf("ZhengChang/n");
            if(ave>80 && ave<=89)
            printf("FeiQiu/n");
        }
        else if(ts == 1)
        {
            printf("ChaoJiOuHuang/n");
        }
    }
    return 0;
    
    

}
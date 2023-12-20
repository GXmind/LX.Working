#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num=0;
    int k=0;
    float test1=0,test2=0;
    int time=0;
    int s[1000]={0};
    while(scanf("%d%d",&num,&k)!=EOF)
    {
        time =0;
        for(int i=1;i<=num;i++)
        {
            test1=i;
            test2=num;
            if((num/i)==(test2/test1))
            {
                time++;
                s[time]=i;
            }
        }
        if(k>time)
        {
            printf("Your number is wrong\n");
        }
        else if(k<=time)
        {
            int ans=1;
            for(int i=1;i<=k;i++)
            {
                ans*=s[i];
            }   
            printf("%d\n",ans);
        }
    }
    return 0;
}


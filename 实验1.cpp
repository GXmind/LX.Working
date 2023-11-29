#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T=0;
    scanf("%d",&T);
    while(T--)
    {
        int y=0;
        vector<int>ans;
        int a=0,b=0,x=0;
        scanf("%d%d%d",&a,&b,&x);
        if(a>=b)
        {

            swap(a,b);
        }
        for(int i=a;i<=b;i++)
        {

                int m,n,d;
                m=i%100/10;
                n=i%10;
                d=i/100;
                if(m+n+d==x)
                {
                    ans.push_back(i);
                    y++;
                }


        }
        int num=1;

        if(y==0)
        {
            printf("None!\n");
        }
        else
        {
            for(int i=0;i<ans.size();i++)
            {
                if(num%10==0)
                {
                    printf("   %d\n",ans[i]);
                }
                else
                {
                    printf("   %d",ans[i]);
                }
                if(num%10!=0&&i==ans.size()-1)
                {
                    printf("\n");
                }
            num++;
            }
        }
        ans.clear();
        
    }
    return 0;
}
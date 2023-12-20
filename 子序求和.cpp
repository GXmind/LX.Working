

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int p,q;
        int ans=0;
        scanf("%d%d",&p,&q);
        for(int m=0;m<n;m++)
        {
            if(m>=p-1&&m<=q-1)
            {
                ans+=s[m];
            }
            
        }
        printf("%d\n",ans);

    }
    return 0;
}
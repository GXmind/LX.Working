/*这里运用kmp的next数组*/
#include <stdio.h>
#include <string.h>

using namespace std;

int next[1000001];
int vis[1000001];
void prefix(string s)/*这里运用kmp的next数组*/
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int Next[1000001];
int vis[1000001];
void prefix(string s)
{
    int j, k;
    j = 0, k = -1;
    Next[0] = -1;
    int lens = s.length();
    while (j < lens)
    {
        if (k == -1 || s[k] == s[j])
        {
            j++;
            k++;
            Next[j] = k;
        }
        else
        {
            k = Next[k];
        }
    }
}
int main()
{
    int i;
    string s;
    while (~scanf("%c", &s))
    {
        memset(vis, 0, sizeof(vis));
        int len = s.length();
        prefix(s);/*kms算法中的前缀函数*/
        /*
        //字符串的下标从一开始
        //前缀函数的实现过程
        void getnext(char p[])
        {
            int m = strlen(p+1);
            next[1]=0;
            for(int k=0,q=2;q<=m;q++)
            {
                while(k>0 && p[k+1] != p[q])
                k=next[k];
                if(p[k+1]==p[q])
                next[q]=k;
            }
        }
        */
        for (i = 1; i < len; i++)
        {
            vis[Next[i]] = 1;/*寻找只能中间有没有出现过字符串*/
        }
        int x = Next[len];/*在循环中如果vis[next[i]=1]则中间出现过可知存在所要寻找的字符串*/
        while (!vis[x] && x != 0)
        {
            x = Next[x];
        }
        if (x == 0)
        {
            printf("Play what play,Roll to study");
        }
        else
        {
            for (i = 0; i < x; i++)
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

{
    int j,k;
    j=0,k=-1;
    next[0]=-1;
    int lens=s.length();
    while(j<lens)
    {
        if(k==-1||s[k]==s[j])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
        {
            k=next[k];
        }
    }
}
int main()
{
    int i;
    string s;
    cin>>s;
    memset(vis,0,sizeof(vis))
    int len=s.length();
    prefix(s);/*kms算法中的前缀函数*/
    /*
    //字符串的下标从一开始
    //前缀函数的实现过程
    void getnext(char p[])
    {
        int m = strlen(p+1);
        next[1]=0;
        for(int k=0,q=2;q<=m;q++)
        {
            while(k>0 && p[k+1] != p[q])
            k=next[k];
            if(p[k+1]==p[q])
            next[q]=k;
        }
    }
    */
    for(i=1;i<len;i++)
    {
        vis[next[i]]=1;/*寻找只能中间有没有出现过字符串*/
    }
    int x=next[len];/*在循环中如果vis[next[i]=1]则中间出现过可知存在所要寻找的字符串*/
    while(!vis[x]&&x!=0)
    {
        x=next[x];
    }
    if(x==0)
    {
        printf("Play what play,Roll to study");
    }
    else
    {
        for(i=0;i<x;i++)
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");

}
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    int yuanshi=1;
    while(T--)
    {

    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
constexpr long long int MOD = 1e9+7,N = 1e5+5;
struct wwt
{
    long long int hard;
    long long int encourage;
}wt[N];
bool cmp(const wwt&a,const wwt&b)
{
    return b.hard * (a.hard + a.encourage) + b.encourage > a.hard * (b.hard + b.encourage) + a.encourage;
}
void pre(long long int t)
{
    for(long long int i = 0;i < t;i++)
    {
        cin >> wt[i].hard >> wt[i].encourage;
    }
    sort(wt,wt+t,cmp);
}
long long fastTimes(long long x,long long y,long long z,long long mod)
{
    long long ans = 0;
    while(y)
    {
        if(y & 1)
        {
            ans = (ans + x) % mod;
        }
        x = x * 2 % mod;
        y >>= 1;
    }
    ans = (ans + z) % mod;
    return ans;
}
void solve(long long int sum,long long int T)
{
    for(long long int i = 0;i < T;i++)
    {
        sum = fastTimes(sum,wt[i].hard % MOD,wt[i].encourage,MOD);
    }
    printf("%lld\n",sum);
}
int main()
{
    long long int T = 0;
    while(~scanf("%lld",&T))
    {
        pre(T);
        long long int sum = 1;
        solve(sum,T);
    }
    return 0;
}

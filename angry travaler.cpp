
#include<bits/stdc++.h>
using namespace std;
constexpr long long int MOD = 1e9+7,N = 1e5+5;
struct assenmint
{
    long long int hard;
    long long int encourage;
}wt[N];
bool cmp(const assenmint&a,const assenmint&b)
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
    while(scanf("%lld",&T)!=EOF)
    {
        pre(T);
        long long int sum = 1;
        solve(sum,T);
    }
    return 0;
}
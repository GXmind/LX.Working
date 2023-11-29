#include<iostream>
#include <algorithm>
using namespace std;
int main() 
{
    long long t, n, x, ans = 0;
    long long  s[200010], q[200010];
    while (cin >> t) 
    {
        while (t--) 
        {
            scanf("%lld%lld", &n, &x);
            for (int i = 1; i <= n; i++) 
            {
                scanf("%lld", &s[i]);
            }
            sort(s + 1, s + n + 1);
            for (int i = 1; i <= n; i++) 
            {
                q[i] = q[i - 1] + s[i];
            }
            if (q[1] > x) 
            {
                printf("0\n");
                ans = 0;
            }
            else 
            {
                int l = 1, r = n;
                while (l < r)
                 {
                    int mid = (l + r + 1) >> 1;
                    if (q[mid] <= x) 
                    {
                        l = mid;
                    } else 
                    {
                        r = mid - 1;
                    }
                }
                ans += l;
                for (int i = 1; i <= r; i++)
                {
                    ans += (x - q[i]) / i;
                }
                printf("%lld\n", ans);
                ans = 0;
            }
        }
    }
    return 0;
}
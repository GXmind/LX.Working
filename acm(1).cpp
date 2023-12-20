
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    long long local;
    int t, i, p, number,  time[101], u = 1, weizhi[100001], vs, l, k=0,h,y;
    scanf("%d", &t);
    for (y = 1;y <= t;y++)
    {
        scanf("%d%lld", &number, &local);
        for (p = 1;p <= number;p++)
        {
            scanf("%d", &time[p]);
        }
        for (i = 1;i <= number;i++)
        {
            weizhi[i] = time[i];
        }

        local = local - number;
        vs = local;
        while (local>0)
        {
            for (p = 1;p <= number;p++)
            {
                h = time[p] - u;
                if (h != 0)
                {
                    time[p] = 1;
                }
                if (h == 0)
                {
                    time[p] = weizhi[p];
                    local = 1;
                }
                
                if (local == 0)
                    k = p;
                if (local == 0)
                    break;
            
            }
        }

        printf("%d\n", k);
        

    }


}
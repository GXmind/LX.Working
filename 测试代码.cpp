#include <bits/stdc++.h>//A.Êı×ÖÉıĞò
using namespace std;
int fun1(int m);
int main()
{
    int n;
    //scanf("%d", &n);
    cin>>n;
    while (n > 0)
    {
        if(fun1(n))
            printf("yes");
        else
           cout<<"no";

        scanf("%d", &n);
    }
}
int fun1( int m )
{
    int k;
    k = m%10;

    while(m)
        if( m / 10 % 10 > k)
            return 0;
        else
        {

            m = m/10;
            k = m % 10;
        }
    return 1;
}
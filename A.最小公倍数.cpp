#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        float x,y,z;
        x=a;
        y=b;
        z=c;
        for(int i=1;i<1000;i++)
        {
            float j=i;
            if(j/a==i/a&&j/b==i/b&&j/c==i/c)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
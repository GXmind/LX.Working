#include<bits/stdc++.h>
#define PI 3.1415

using namespace std;

int main()
{
    double r=0;
    while(scanf("%lf",&r)!=EOF)
    {
        double area=0;
        double volumes=0;
        double square=0;
        area=PI*r*r;
        volumes=4.0/3.0*PI*r*r*r;
        square=4*PI*r*r;
        //控制输出相同位数的数字答案
        printf("%g %g %g\n",area,volumes,square);
        //%g控制输出符号

    }    
    return 0;

}
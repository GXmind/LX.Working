#include <stdio.h>
#include <string.h>
#include <math.h>
struct Triangle
{
    double area=0;
    double perimeter=0;
    bool condition=false;
};
int main()
{
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        Triangle triangle;
        if(a+b>c&&a+c>b&&b+c>a)
        {
            triangle.condition=true;
        }
        if(triangle.condition==false)
        {
            printf("cannot consist of a triange!\n");
        }
        else
        {
            double p;
            p=(a+b+c)/2;
            double ans;
            ans=(p-a)*(p-b)*(p-c);
            triangle.area=sqrt(ans*p);
            triangle.perimeter=a+b+c;
            printf("area:%.2lf,perimeter:%.2lf\n",triangle.area,triangle.perimeter);
        }
    }
}
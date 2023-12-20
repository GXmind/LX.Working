#include <stdio.h>
#define PI 3.1415/*将PI进行宏定义*/
int main()
{  
    double s,v;  /*定义变量,面积,体积*/
    int r;/*定义半径*/
    while(~scanf("%d",&r))
    {
       
        s = 4*PI*r*r; /*求球体的表面积公式*/
        v = 4/3*PI*r*r*r;/*求球的体积公式*/
        printf("%.2lf\n",s);/*输出球的表面积*/
        printf("%.2lf\n",v);

    }
}

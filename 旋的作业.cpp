#include <stdio.h>
#define PI 3.1415/*��PI���к궨��*/
int main()
{  
    double s,v;  /*�������,���,���*/
    int r;/*����뾶*/
    while(~scanf("%d",&r))
    {
       
        s = 4*PI*r*r; /*������ı������ʽ*/
        v = 4/3*PI*r*r*r;/*����������ʽ*/
        printf("%.2lf\n",s);/*�����ı����*/
        printf("%.2lf\n",v);

    }
}

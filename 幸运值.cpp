// 旅行者有n个五星角色，每个五星角色花费旅行者ai抽。
// 请你计算旅行者获取每个五星角色的平均抽数x，
// 如果1<=x<=30,那么该旅行者的幸运程度是ChaoJiOuHuang(超级欧皇)。
// 如果30<x<=60,那么该旅行者的幸运程度是OuHuang(欧皇)。
// 如果 60<x<=80,那么该旅行者的幸运程度为ZhengChang(正常)。
// 如果 80<x<=89,那么该旅行者的幸运程度是FeiQiu(非酋)。
// 特别的，如果该旅行者花费了90抽来获取任意一个五星角色，那么他也是超级欧皇。

//测试样例如下

// 3
// 5
// 24 26 32 22 36
// 5
// 81 82 83 84 85
// 5
// 89 89 90 89 89

//经过实验，不用goto才最终AC
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num1=0;
    scanf("%d",&num1);
    for(int i=0;i<num1;i++)
    {
        int totle=0;
        int average=0;
        int num2=0;
        int special=0;
        scanf("%d",&num2);
        int s[num2];
        for(int m=0;m<num2;m++)
        {
            scanf("%d",&s[m]);
            totle+=s[m];
            if (s[m]==90)
            {
                special=1;
            }
        }
        average=totle/num2;
        if(special!=1)
        {
            if(average>80)
            {
                printf("FeiQiu\n");
            }
            else if(average>60)
            {
                printf("ZhengChang\n");
            }
            else if(average>30)
            {
                printf("OuHuang\n");
            }
            else if(average>=1)
            {
                printf("ChaoJiOuHuang\n");
            }
        }
        
        if(special==1)
        {
            printf("ChaoJiOuHuang\n");
        }
    }
    return 0;  
}
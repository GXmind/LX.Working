// ��������n�����ǽ�ɫ��ÿ�����ǽ�ɫ����������ai�顣
// ������������߻�ȡÿ�����ǽ�ɫ��ƽ������x��
// ���1<=x<=30,��ô�������ߵ����˳̶���ChaoJiOuHuang(����ŷ��)��
// ���30<x<=60,��ô�������ߵ����˳̶���OuHuang(ŷ��)��
// ��� 60<x<=80,��ô�������ߵ����˳̶�ΪZhengChang(����)��
// ��� 80<x<=89,��ô�������ߵ����˳̶���FeiQiu(����)��
// �ر�ģ�����������߻�����90������ȡ����һ�����ǽ�ɫ����ô��Ҳ�ǳ���ŷ�ʡ�

//������������

// 3
// 5
// 24 26 32 22 36
// 5
// 81 82 83 84 85
// 5
// 89 89 90 89 89

//����ʵ�飬����goto������AC
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
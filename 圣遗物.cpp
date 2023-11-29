//圣遗物

// 有多组测试样例
// 对于每一个样例
// 一个整数n，表示圣遗物的个数，(1<=n<=200)
// 接下来是n个圣遗物的种类以及他们的基础值。(1<=基础值<=1000)
// 有多组测试样例
// 对于每一个样例
// 唯一的一个整数，基础值加和的最大值。
// 若不能从每种圣遗物中选出一个，则输出-1.
// 末尾有换行

//测试样例如下

//input
// 10
// tou 111
// bei 222
// mao 333
// hua 444
// sha 555
// tou 666
// bei 777
// mao 888
// hua 999
// sha 1000

//output
//4330

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum;
    while(scanf("%d",&sum)!=EOF)
    {
        int tou[200]={0};
        int bei[200]={0};
        int mao[200]={0};
        int hua[200]={0};
        int sha[200]={0};

        int t=0;
        int b=0;
        int m=0;
        int h=0;
        int s=0;

        for(int i=0;i<sum;i++)
        {
            string scan;

            string s1="tou";
            string s2="bei";
            string s3="mao";
            string s4="hua";
            string s5="sha";

            int value=0;
            
            cin>>scan>>value;
            if (scan =="tou")
            {
                tou[t]=value;
                t++;
            }
            else if (scan =="bei")
            {
                bei[b]=value;
                b++;
            }
            else if (scan =="mao")
            {
                mao[m]=value;
                m++;
            }
            else if (scan =="hua")
            {
                hua[h]=value;
                h++;
            }
            else if (scan =="sha")
            {
                sha[s]=value;
                s++;
            }

            
        }
        sort(tou,tou+200);
        sort(bei,bei+200);
        sort(mao,mao+200);
        sort(hua,hua+200);
        sort(sha,sha+200);

        int ans=0;
        if(tou[199]==0||bei[199]==0||mao[199]==0||hua[199]==0||sha[199]==0)
        {
            printf("-1\n");
        
        }
        else
        {
            ans+=tou[199];
            ans+=bei[199];
            ans+=mao[199];
            ans+=hua[199];
            ans+=sha[199];
            printf("%d\n",ans);
        }
        
    }
    return 0;
}
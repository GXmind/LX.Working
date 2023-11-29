//唬牌是一种扑克游戏，包含A,2,3,4,5,6,7,8,9,10,J,Q,K各四张。
// 有四个玩家参与这个游戏。
// 每一位玩家在游戏开始时都会有随机的13张牌。
// 在桌子上没有牌时，玩家选择任意一个点数x和一个数字y(y小于等于手中牌数且至少为一),并打出任意y张牌，并将这y张牌的背面朝上放在桌上，声称"这是y张x牌"。
// 当桌子上有牌时，玩家可以选择两种操作
// （1）选择一个数字z，并打出任意z张牌，声称"这是z张x牌"，注意：x与上一位打出牌的玩家所选的点数相同。
// （2）质疑上一位玩家，然后他将翻转上一位玩家打出的牌，并检查上一位玩家的陈述是否正确。
//  若质疑成功（上一位玩家的陈述与其打出的牌不符），则被质疑者拿走桌上所有的牌。
//  若质疑失败，则质疑者拿走桌上所有的牌。
// 当一个玩家选择质疑，并且在某位玩家拿了桌上所有的牌之后，如果有玩家手里没有牌，那么我们就说这个玩家赢了这场游戏。
// 为了简化，这次您需要编写一个程序来模拟游戏过程，在程序中，用1代表A，11代表J，12代表Q，13代表K

//input
// 有t组样例
// 对于每一个样例
// 首先是4行，第i行包含13个数字，第i位玩家手中的牌
// 然后一行包含一个整数m (2 <=m <= 20)，表示游戏回合数。接下来的m行，每一行都是以下格式之一:
// 1. ”S x y a1 a2 ……ay“，意思是当前的玩家出牌a1, a2，...， ay，并声明“这些是y张x牌”。
// 2. “! y a1 a2…，ay”，意思是当前的玩家选择不质疑，并打出y张牌a1, a2... ay，并声明“这些是y张牌x”，其中x保持不变(仍是上次说明的x）
// 3. “?“，表示当前玩家选择提出问题。 测试保证所有操作都是合法的。在这个过程中，没有人会赢。

//output
// 对于每一个样例
// 输出四行，第i位玩家在m回合后，非递减顺序牌。
// 每一行末尾有空格
// 末尾包含换行

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int group=0;
    while(group--)
    {
        vector<int>arr1;
        vector<int>arr2;
        vector<int>arr3;
        vector<int>arr4;
        for(int i=0;i<13;i++)
        {
            scanf("%d",&arr1[i]);
        }
        for(int i=0;i<13;i++)
        {
            scanf("%d",&arr2[i]);
        }
        for(int i=0;i<13;i++)
        {
            scanf("%d",&arr3[i]);
        }
        for(int i=0;i<13;i++)
        {
            scanf("%d",&arr4[i]);
        }
        int process=0;
        scanf("%d",&process);
        int num=0;//桌上牌的总序数
        while(process--)
        {   
            bool valueS=true;//声明
            bool valueM=true;//不质疑
            int x=0,y=0;
            int t=4;
            int arr_A[52]={0};//桌上牌的总数
            while(t--)
            {
               
                string kind;
                int mode=1;
                scanf("%s",&kind);
                //声明出牌
                if(kind=="S")
                {
                    scanf("%d%d",&x,&y);
                    int S[x];
                    
                    for(int i=0;i<x;i++)
                    {
                        scanf("%d",S[i]);
                        arr_A[i]=S[i];
                        if(S[i]!=y)
                        {
                            valueS=false;
                        }
                    }
                    num+=x;
                    mode=1;
                }
                //不声明出牌
                else if(kind=="!")
                {
                    scanf("%d",&y);

                    int M[x];
                    for(int i=0;i<x;i++)
                    {
                        scanf("%d",M[i]);
                        
                        arr_A[x]=M[i];
                        
                        if(M[i]!=y)
                        {
                            valueM=false;
                        }
                    }
                    num+=x;
                    mode=2;
                }
                //质疑
                else if(kind=="?")
                {
                    //质疑声明出牌
                    if(mode==1)
                    {
                        if(valueS==true)
                        {

                        }
                        else
                        {

                        }
                    }
                    //质疑不声明出牌
                    if(mode==2)
                    {
                        if(valueM==true)
                        {

                        }
                        else
                        {
                            
                        }
                    }
                
                }

            }
            
        }
        
        for(int i=0;i<13;i++)
        {
            printf("%d ",arr1[i]);
        }
        printf("\n");
        for(int i=0;i<13;i++)
        {
            printf("%d ",arr2[i]);
        }
        printf("\n");
        for(int i=0;i<13;i++)
        {
            printf("%d ",arr3[i]);
        }
        printf("\n");
        for(int i=0;i<13;i++)
        {
            printf("%d ",arr4[i]);
        }
        printf("\n");
    }
    return 0;
}
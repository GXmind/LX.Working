#include<bits/stdc++.h>
using namespace std;
int gugu(int number)
{
    for(int i=3;i<10;i+=2)
    {
        if((number-i)%2!=0&&(number-i)!=9)
        {
            printf("%d=%d+%d\n",number,i,number-i);
            break;
        }
    }
    return 0;
}
int main()
{
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    for(int n=num1;n<=num2;n++)
    {
        gugu(n);
    }
    return 0;
}
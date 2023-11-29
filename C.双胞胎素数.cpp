#include<bits/stdc++.h>
using namespace std;
int main()

{
    vector<int>obj;
    int j,i,n;
    int sum=0;
    int num1,num2;
    while(scanf("%d %d",&num1,&num2)!=EOF)
    {
    
    if(num1>num2)
    {
        swap(num1,num2);
    }
    for(i=num1;i<=num2;i++)
    {
        for(n=2;n<=i;n++)
        {
            if(i%n==0)
            {
                break;
            }
        }
        if(i==n)    
        {
            for(j=2;j<=(i+2);j++)
            {
                if((i+2)%j==0)
                break;
            }
            int time=0;
            if((i+2)==j&&(i+2)<num2)
            {
                obj.push_back(i);
                obj.push_back(i+2);
            }
        }
    }
    int time=0;
    
    for(int i=0;i<obj.size();i++)
    {
        printf("%6d",obj[i]);
        time++;
        if(time==10)
        {
            time=0;
            printf("\n");
        }
    }
    printf("\n");
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num1=0;
    while(scanf("%d",&num1)!=EOF)
    {
        int num2=0;
        double s[num1];
        double totle=0;
        for(int i=0;i<num1;i++)
        {
            scanf("%lf",&s[i]);
            totle+=s[i];
        }
        totle/=num1;
        for(int i=0;i<num1;i++)
        {
           s[i]-=totle;
        }

        for(int i=0;i<num1;i++)
        {
            if(i!=num1-1)
            {
                printf("%g ",s[i]);
            }
            else
            {
                printf("%g",s[i]);
            }
            
        }
        printf("\n");

    }
    
    return 0; 
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int number=0;
    while(scanf("%d",&number)!=EOF)
    {
        int high_line=(number-1)/2;
        int low_line=(number-1)/2;
        int mid_line=1;
        //ace part
        for(int i=(number-1)/2;i>0;i--)
        {
            printf(" ");  
        }
        printf("*\n");
        //middle part
        //one upper
        high_line--;
        int num=1;
        for(int i=high_line;i>0;i--)
        {
            
            for(int j=i;j>0;j--)
            {
                printf(" ");
            }
            printf("*");
            for(int k=num;k>0;k--)
            {
                printf(" ");
            }
            printf("*\n");
            num+=2;
        }
        //two middle
        num+=2;
        printf("*");
        for(int i=number-2;i>0;i--)
        {
            printf(" ");
        }
        printf("*\n");
        //three lower
        low_line--;
        int num2=0;
        num=number-2;
        for(int i=low_line;i>0;i--)
        {
            num-=2;
            num2++;
            for(int k=num2;k>0;k--)
            {
                printf(" ");
            }
            printf("*");
            for(int j=num;j>0;j--)
            {
                printf(" ");
            }
            printf("*\n");
        }
        //bottom part
        for(int i=(number-1)/2;i>0;i--)
        {
            printf(" ");  
        }
        printf("*\n");

    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[100] ;
    int sum = 0;
    int s[10]={0};
    while(gets(str)!=NULL)
    {
        for(int i=0; str[i]!='\0'; i++)
        {
            if(str[i]=='0')
            {
                s[0]++;
            }
            else if(str[i]=='1')
            {
                s[1]++;
            }
            else if(str[i]=='2')
            {
                s[2]++;
            }
            else if(str[i]=='3')
            {
                s[3]++;
            }
            else if(str[i]=='4')
            {
                s[4]++;
            }
            else if(str[i]=='5')
            {
                s[5]++;
            }
            else if(str[i]=='6')
            {
                s[6]++;
            }
            else if(str[i]=='7')
            {
                s[7]++;
            }
            else if(str[i]=='8')
            {
                s[8]++;
            }
            else if(str[i]=='9')
            {
                s[9]++;
            }
        }
        for(int i=0;i<10;i++)
        {
            printf("%3d",s[i]);
        }
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void funs(char a)
{
    if (a=='1')
    {
        printf("1");
    }
    if (a=='3')
    {
        printf("3");
    }
    if (a=='5')
    {
        printf("5");
    }
    if (a=='7')
    {
        printf("7");
    }
    if (a=='9')
    {
        printf("9");
    }
}
int main()
{
    char s[100];
    while(gets(s))
    {
        for(int i=0;s[i]!='\0';i++)
        {
            funs(s[i]);

        }
        printf("\n");
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;


char a[100], b[100],c[100];

void function_hugenumber_plus (char a[], char b[])
{
    memset(c, 0, sizeof(c));
    int c_len, a_len, b_len;
    c_len = a_len = strlen(a);
    b_len=strlen(b);
    int i, j;
    for(i=a_len-1,j=0;i>=0;i--)
    c[j++]=a[i]-'0';

    if(b_len>c_len)
    {
        c_len=b_len;
    }
    int carry=0;
    for(i=b_len-1,j=0;i>=0;i--,j++)
    {
        c[j]+=b[i]-'0'+carry;
        carry=c[j]/10;
        c[j]%=10;
    }
    while(carry>0)
    {
        c[j]+=carry;
        carry=c[j]/10;
        a[j++]%=10;
    }
    if(j>c_len)
    {
        c_len=j;
    }
    
    for(i=c_len-1;i>=0;i--)
    {
        if(c[i])
        {
            break;
        }
    }
    if(i<0)
    {
        i=0;
    }
   
    for(;i>=0;i--)
    {
        printf("%d",c[i]);
    }
    printf("\n");
    return ;
}
int main()
{
    while(gets(a), gets(b))
    {
        function_hugenumber_plus(a, b); 
    }
    return 0;
}
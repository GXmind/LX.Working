#include<stdio.h>
#include <string.h>
int main()
{
char ss[100];
int i,a,b,c,d,e,f,g,h,j,k,n;
gets(ss);
 a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,k=0,n=0;
 for(i=0;ss[i]!='\0';i++)
 {
    if(ss[i]=='0')
    a++;
    else
    if(ss[i]=='1')
         b++;
    else
    if(ss[i]=='2')
     c++;
    else
    if(ss[i]=='3')
     d++;
    else
    if(ss[i]=='4')
     e++;   
    else
    if(ss[i]=='5')
     f++;
    else
    if(ss[i]=='6')
     g++;
    else
    if(ss[i]=='7')
     h++;
    else
    if(ss[i]=='8')
    j++;
    else
    if(ss[i]=='9')
     k++;
    }
     printf("%d %d %d %d %d %d %d %d %d %d",a,b,c,d,e,f,g,h,j,k);

}
#include <stdio.h>
#include <string.h>
int main()
{
    char cl[1000];
    char a;
    while(~scanf("%c",&a))
    {
        if(a='A')
        {

        }
        if(a='B')
        {
            int sum=0,b;
            gets(cl);
            strlwr(cl);
            b=strlen(cl);
            for(int i=0;i<b;i++)
            {
                if(cl[i]>='a'&&cl[i]<='z')
                   { sum++;}
                   printf("%d",sum);
            }
        }
        if(a='C')
        {
            int sum=0,b;
           while()
                if(cl[i]>='0'&&cl[i]<='9')
                {
                    sum++;
                }
                printf("%d",sum);
            }
        }
    }
}
#include <stdio.h>
int main()
{
    int j,a,max,r[100];
    while(~scanf("%d",&a))
    {
        int s[100][100];
        for(int i=0;i<a;i++)
            for(int j=0;j<a;j++)
                scanf("%d",&s[i][j]);
        for(int j=0;j<a;j++)
        {
            max=s[0][j];
            for(int i=1;i<a;i++)
                if(s[i][j]>max)
                max=s[i][j];
                r[j]=max;
        }
        for(int j=0;j<a;j++)
        {
            if(j==a-1)
            {
                printf("%d\n",r[j]);
            }
            else
            {printf("%d,",r[j]);}
        }
        

        


        
    }
}
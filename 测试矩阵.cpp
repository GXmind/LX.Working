#include<stdio.h>
int main()
{
    int a;
    while(~scanf("%d",&a))
    {
    int i,j,row,column,m;
    static int array[3][3] {{100,200,300},{28,72,-30},{-850,2,6}};
    m=array[0][0];
    for (i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(array[i][j]<m)
                {
                    m=array[i][j];
                    row=i;
                    column=j;
                }
    printf("%d,%d,%d\n",m,row,column);
    }
        
}
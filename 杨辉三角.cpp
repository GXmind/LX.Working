#include <stdio.h>

void triangle(int b)
{
	
	
	
	int a[100][100];
	for(int i=0;i<b;i++)
	{
		a[i][0]=1;
		a[i][i]=1;   
	}
	
	for(int i=2;i<b;i++)    
	{
		for(int j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	
	
	for(int i=0;i<b;i++)     
	{
		for(int j=0;j<=i;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
};
int main()
{
    int linenumber;
    scanf("%d",&linenumber);
    linenumber++;
    triangle(linenumber);
    return 0;
}
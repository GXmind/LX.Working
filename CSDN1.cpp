#include<stdio.h>	
int main()
{
	int i;
	int n[100];
	int m;
    while(~scanf("%d",&m)){
    for(i=0;i<m;i++)
	{
		scanf("%d",&n[i]);
	}
	int j, temp;
	for (i = 1; i <= m-1; i++)
	{
		for (j = 0; j <= m-1 - i; j++)
		{
			if (n[j] > n[j + 1])
			{
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < m; i++)
	printf("%d ", n[i]);
	printf("\n");}
}

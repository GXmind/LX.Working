#include<stdio.h>
int main()
{
	int i,j,k,n,a;
	while(~scanf("%d",&n)){
	if(n%2==0)
	{
		printf("Error");
		return 0;
	}
	else
	{
		a=(n+1)/2;
		for(i=0;i<a;i++)
		{
			for(j=0;j<a-i-1;j++)
				printf(" ");
			printf("*");
			if(i!=0)
			{
				for(k=0;k<2*i-1;k++)
					printf(" ");
				printf("*");
			}
			printf("\n");
		}
		for(i=a-2;i>=0;i--)
		{
			for(j=0;j<a-i-1;j++)
				printf(" ");
			printf("*");
			if(i!=0)
			{
				for(k=0;k<2*i-1;k++)
					printf(" ");
				printf("*");
			}
			printf("\n");
		}
	}}
	return 0;
} 
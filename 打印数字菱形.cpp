#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

void number(int num1)
{
		int num2 = num1;
		for (int i = num1; i > 0; i--)
		{
			printf("%d", num2);
			num2--;
		}
		num2 += 2;

		for (int o = num1 - 1; o > 0; o--)
		{
			printf("%d", num2);
			num2++;
		}
}

int main()
{
	int time = 0;
	scanf("%d", &time);
	while (time--)
	{

		int line;
		scanf("%d", &line);
		line = line * 2 + 1;
		int a = (line + 1) / 2;
		int e = 1;
		int q = a;
		int y = a;
		while (q--)
		{

			for (a; a > 0; a--)
			{
				printf(" ");
			}
			y--;
			a = y;

			number(e);
			e++;
			printf("\n");
		}

		e -= 2;

		int b = (line + 1) / 2-1;
		int w = b;
		int x = 2;
		int u = 2;
		while (w--)
		{
			while (x--)
			{
				printf(" ");
				
			}
			u++;
			x=u;
			number(e);
			e--;
			printf("\n");
		}
	}

	return 0;
}
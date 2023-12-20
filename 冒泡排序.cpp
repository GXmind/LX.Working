#include<iostream>
#include<stdio.h>

int main() 
{

	
	int arr[11] = { 0 };
	for (int i = 10; i > 0; i--)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 11 - 1; i++)
	{
		for (int j = 0; j < 11 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	printf("the sorted numbers:\n");

	for (int i = 1; i < 11; i++)
	{
		
		printf("%d ", arr[i]);
	}

	

	return 0;
}
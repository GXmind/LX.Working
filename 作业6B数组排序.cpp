#include<bits/stdc++.h>
using namespace std;
int shuzu(int arr[],int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
	for (int *p= arr; p != arr+len-1; p++)
	{

		cout<<*p<<',';
	}
	printf("%d",arr[len-1]);
    return 0;
}

int main()
{
    int array[100]={0};
    int i=0;
    while(cin>>array[i])
    {
		if(cin.get()=='\n')
            break;
        i++;
    }
    int length=0;
    for(int i=0;i<100;i++)
    {
        if(array[i]!=0)
        {
            length++;
        }
    }

    shuzu(array,length);
    return 0;
}
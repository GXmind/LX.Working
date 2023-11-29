#include <bits/stdc++.h>
using namespace std;
int age(int n)
{
	int ans;
	if(n==1)
    {
        ans=10;
    }
		 
	else if(n!=1)
    { 
		ans=age(n-1)+2;
	} 
	return ans;	
} 
int main()
{
 	int number=5;
 	printf("%d\n",age(number));
 	return 0;
}
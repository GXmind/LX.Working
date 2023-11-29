#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std; 
int compare(string str1,string str2)
{
	int a;
	int i;
	if(str1==str2)
	{
		return 0;
	}
	else
	{
		for(i=0;(str1[i]!='\0')&&(str2[i]!='\0');i++)
		{
			a=str1[i]-str2[i];
			if(a!=0)
			break;	
		}
		return a;
	}
}
int main()
{
	string str1,str2;
	while(getline(cin,str1))
	{
		getline(cin,str2);
		int ans=0;
		ans=compare(str1,str2);
		printf("%d\n",ans);
	}
}

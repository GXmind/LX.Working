
#include<bits/stdc++.h>
using namespace std;
int main_function(string array[], int len)
{
    int max=0;
    int max_number=0;
    for(int i=0;i<len;i++)
    {
        if(max_number<=array[i].length())
        {
            max_number=array[i].length();
            max=i;
        }
    }
    return max;
}
int main()
{
    int time=0;
    while(scanf("%d",&time)!=EOF)
    {
        string s[time];
        int length=time;
        for(int i=0;i<time;i++)
        {
            cin>>s[i];
        }
        int ans;
        ans=main_function(s,length);
        cout<<s[ans]<<endl;
    }
    return 0;
}
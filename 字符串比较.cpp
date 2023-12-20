#include <bits/stdc++.h>
using namespace std;
int function1(string str1,string str2)
{
    int t;
    if(str1==str2)
        return 0;
    else
    {
       for(int i=0;i<=(int)str1.size();i++)
       {
       t=str1[i]-str2[i];
        if(t!=0)
        break;
       }
        return t;
    }
}
int main()
{
    string str1,str2;
   while(getline(cin,str1))
{
    getline(cin,str2);
    int answer=0;
    answer=function1(str1,str2);
    cout<<answer<<"\n";
}
    return 0;
}
#include <bits/stdc++.h>//A.�����������ͷ�ļ�������ͷ
using namespace std;//������һ��using namespace std;�����c++�������ռ�

int HanShu(int m)
{
    int k;
    k=m%10;
    while(m!=0)
    {

        if(m/10%10>k)
        {
            return 0;
        }
        else
        {
            //m=m/10;k=m%10;
            k=m/10%10;//�������⣬�������һ������Ϊʲô����������У����治��
            
        }
        
    }
     return 1;
   
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans;
      ans=HanShu(n);
      if(ans==1)
        cout<<"yes\n";
      else
        cout<<"no\n";//c++�������Ϊcout ��cΪprintf��c++��������Ϊcin����cΪscanf
    }
 return 0;
}
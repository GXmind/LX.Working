#include <bits/stdc++.h>//A.数字升序，这个头文件是万能头
using namespace std;//这里有一个using namespace std;这个是c++的命名空间

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
            k=m/10%10;//问题在这，这里和上一排区别，为什么上面可以运行，下面不行
            
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
        cout<<"no\n";//c++里面输出为cout 而c为printf，c++里面输入为cin、，c为scanf
    }
 return 0;
}
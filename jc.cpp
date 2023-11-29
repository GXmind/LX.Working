#include <iostream> 
using namespace std;
 int calculateProduct(int n) 
 { 
    if (n == 1) 
    { 
        return 1;
         } 
         else 
         { 
            return n * calculateProduct(n - 1); 
            } 
} 
int main() 
{ 
int n; cout << "请输入一个正整数 n："; 
cin >> n; 
int result = calculateProduct(n); 
cout << "结果为：" << result << endl; 
return 0; 
}
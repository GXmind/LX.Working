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
int n; cout << "������һ�������� n��"; 
cin >> n; 
int result = calculateProduct(n); 
cout << "���Ϊ��" << result << endl; 
return 0; 
}
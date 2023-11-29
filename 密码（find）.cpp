/*这里运用kmp的next数组*/
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


int main()
{
 string s;
 cin >> s;
 for (int i = s.length() - 1; i >= 1; i--) {
  string a = s.substr(0, i);//abcxxabcxxabc
  //cout << "a:" << a << "\n";
  string b = s.substr(s.length() - i, i);
  //cout << "b:" << b << "\n";
  string t = s.substr(1, s.length() - 2);
  //cout << "t:" << t << "\n";
  if (a == b && t.find(a) != string::npos) {
   cout << a << endl;
   return 0;
  }
 }
 cout << "Play what play,Roll to study" << endl;
 return 0;
}
#include<math.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<stack>
#include<algorithm>
using namespace std;
char m[1005];//字母名称
stack<char>s, o;
string change(int n)
{
	string str1;
	int cnt = 0;
	string ans;
	while (n)
	{
		str1 += n % 2 + '0';
		n = n / 2;
	}
	string re;
	if (str1 == re)
	{
		str1 = '0';
	}
	reverse(str1.begin(), str1.end());
	return str1;
}//二进制转换
const char and_cal(char a, char b)
{
	if (a == '1' && b == '1')return '1';
	else return '0';
}
const char or_cal(char a, char b)
{
	if (a == '1' || b == '1')
		return '1';
	else return '0';
}
const char two_cal(char a, char b)
{
	if ((a == '1' && b == '1') || (a == '0' && b == '0'))return '1';
	else return '0';
}
const char no_cal(char a)
{
	if (a == '0')return '1';
	else return '0';
}
const char one_cal(char a, char b)
{
	if (a == '1' && b == '0')return '0';
	else return '1';
}//5个运算规则


int main()
{
	cout << "\t真值表判断\n";
	cout << "规则：\n";
	cout << "输入公式要由（ ）确定优先级\n";
	cout << "(1) 用 ! 代替 非 操作\n(2) 用 && 代替 ∧ 操作\n(3) 用 || 代替 ∨ 操作\n(4) 用 <> 代替 双条件 操作\n(5) 用 - 代替 → 操作\n";
	string str;
	string strre;//复制str在以后的每次改变中起到复原作用
	int cnt = 0;
	cin >> str;
	strre = str;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]))
		{
			for (int j = 0; j < cnt; j++)
			{
				if (str[i] == m[j])
					continue;
			}
			m[cnt++] = str[i];//字母种类
		}

	}//找到字母
	sort(m, m + cnt);
	for (int i = 0; i < cnt; i++)
		printf("%c\t", m[i]);
	cout << str << "\n";
	int d = pow(2, cnt);
	for (int a = 0; a < d; a++)
	{
		str = strre;//每一次替换都会改变原式，此处恢复原式
		while (!s.empty())s.pop();
		int go = 0;
		string num = change(a);//num为二进制表
		int aa = cnt;
		for (int i = 0; i < cnt; i++)
		{
			char rr = m[i];//记录当前准备替换的字母
			int re = num.length() - aa;
			if (re < 0)
			{
				cout << "0\t";
				for (int d = 0; d < str.length(); d++)
					if (str[d] == rr)str[d] = '0';
			}//二进制前导0处理
			else
			{
				char nn = num[num.length() - aa];
				cout << nn << "\t";
				for (int d = 0; d < str.length(); d++)
					if (str[d] == rr)str[d] = nn;
			}
			aa--;
		}//字母替换
		for (int i = 0; i < len; i++)
		{
			s.push(str[i]);
			if (str[i] == ')')
			{
				s.pop();//弹出右括号
				while (!o.empty())o.pop();
				while (s.top() != '(')
				{
					o.push(s.top());
					s.pop();
				}
				s.pop();//弹出前括号

				while (o.size() != 0)
				{
					char k = o.top();
					o.pop();
					if (o.top() == '&')
					{
						o.pop();
						o.pop();
						char c = and_cal(k, o.top());
						s.push(c);
						o.pop();
					}
					else if (o.top() == '|')
					{
						o.pop();
						o.pop();
						char c = or_cal(k, o.top());
						o.pop();
						s.push(c);
					}
					else if (o.top() == '<')
					{
						o.pop();
						o.pop();
						char c = two_cal(k, o.top());
						o.pop();
						s.push(c);
					}
					else if (k == '!')
					{
						char c = no_cal(o.top());
						s.push(c);
						o.pop();
					}
					else if (o.top() == '-')
					{
						o.pop();
						char c = one_cal(k, o.top());
						o.pop();
						s.push(c);
					}
				}

			}
		}//去除括号
		while (s.size() != 0)
		{
			if (s.size() == 1)
			{
				cout << s.top() << endl;
				break;
			}
			char k = s.top();
			s.pop();
			if (s.top() == '&')
			{
				s.pop();
				s.pop();
				char c = and_cal(k, s.top());
				s.pop();
				s.push(c);
			}
			else if (s.top() == '|')
			{
				s.pop();
				s.pop();
				char c = or_cal(k, s.top());
				s.pop();
				s.push(c);
			}
			else if (s.top() == '>' || s.top() == '<')
			{
				s.pop();
				s.pop();
				char c = two_cal(k, s.top());
				s.pop();
				s.push(c);
			}
			else if (s.top() == '!')
			{
				s.pop();
				char c = no_cal(k);
				s.push(c);
			}
			else if (s.top() == '-')
			{
				s.pop();
				char c = one_cal(s.top(), k);
				s.pop();
				s.push(c);
			}
		}
	}
}

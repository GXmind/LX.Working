/*这里运用kmp的next数组*/
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int Next[1001];
int vis[1001];
void prefix(string s)
{
    int j, k;
    j = 0, k = -1;
    Next[0] = -1;
    int lens = s.length();
    while (j < lens)
    {
        if (k == -1 || s[k] == s[j])
        {
            j++;
            k++;
            Next[j] = k;
        }
        else
        {
            k = Next[k];
        }
    }
}
int main()
{
    int i;
    string s;
    cin >> s;
    
        memset(vis, 0, sizeof(vis));
        int len = s.length();
        prefix(s);/*kms算法中的前缀函数*/
        /*
        //字符串的下标从一开始
        //前缀函数的实现过程
        void getnext(char p[])
        {
            int m = strlen(p+1);
            next[1]=0;
            for(int k=0,q=2;q<=m;q++)
            {
                while(k>0 && p[k+1] != p[q])
                k=next[k];
                if(p[k+1]==p[q])
                next[q]=k;
            }
        }
        */
        for (i = 1; i < len; i++)
        {
            vis[Next[i]] = 1;/*寻找只能中间有没有出现过字符串*/
        }
        int x = Next[len];/*在循环中如果vis[next[i]=1]则中间出现过可知存在所要寻找的字符串*/
        while (!vis[x] && x != 0)
        {
            x = Next[x];
        }
        if (x == 0)
        {
            printf("Play what play,Roll to study");
        }
        else
        {
            for (i = 0; i < x; i++)
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    cin >> s;
    return 0;
}

/*��������kmp��next����*/
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
        prefix(s);/*kms�㷨�е�ǰ׺����*/
        /*
        //�ַ������±��һ��ʼ
        //ǰ׺������ʵ�ֹ���
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
            vis[Next[i]] = 1;/*Ѱ��ֻ���м���û�г��ֹ��ַ���*/
        }
        int x = Next[len];/*��ѭ�������vis[next[i]=1]���м���ֹ���֪������ҪѰ�ҵ��ַ���*/
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

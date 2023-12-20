#include<bits/stdc++.h>


int main()
{
    char a[7], ch;
    int top, mid, bot;
    gets(a);
    scanf("%c", &ch);
    top = strlen(a) - 1;
    for (bot = 0; bot <= top;1)
    {
            mid = (top + bot) / 2;
            if (ch == a[mid])
            {
            printf("%d\n", mid + 1);
            break;
            }
            else if (ch > a[mid])
            bot = mid + 1;
            else
            top = mid - 1;
    }
    if (bot > top)
    {
        printf("*\n");
    }
   
  return 0;
}
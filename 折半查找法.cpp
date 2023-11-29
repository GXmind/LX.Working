#include<bits/stdc++.h>


int main()
{
    char a[100], ch;
    int top, mid, bot;

    gets(a);

    scanf("%c", &ch);
    for (bot = 0, top = strlen(a) - 1; bot <= top;)
    {
            mid = (top + bot) / 2;
            if (ch == a[mid])
            {
            printf("%d", mid + 1);
            break;
            }
            else if (ch > a[mid])
            bot = mid + 1;
            else
            top = mid - 1;
    }
  if (bot > top)
    printf("*\n");
   
  return 0;
}
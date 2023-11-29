#include <stdio.h>
int func(int num) 
{
    return ((num > 0) && ((num & (num - 1)) == 0));
}
int main()
{
    int result;
    unsigned int m;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==1)
        {
            printf("0\n");
        }
        else{
        result = func(m);
        printf("%d\n",result);}
    }
    return 0;

}


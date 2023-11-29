#include<stdio.h>
int main()
{
	char s[100];
	int i,k, num[10]={0};  
	
	while(gets(s))
	{
	
	for(i=0; s[i]!='\0'; i++)
	{
		switch(s[i]){
			case '0':	num[0]++;  break;
			case '1':	num[1]++;  break;
			case '2':	num[2]++;  break;
			case '3':	num[3]++;  break;
			case '4':	num[4]++;  break;
			case '5':	num[5]++;  break;
			case '6':	num[6]++;  break;
			case '7':	num[7]++;  break;
			case '8':	num[8]++;  break;
			case '9':	num[9]++;  break;

		}
	}
	
	for(i=0; i<10; i++)	
	printf("%d  ",num[i]);
    printf("\n");
    for(i=0; i<10; i++)	
	num[i]=0;
    }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
//zero,one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen,twenty,thirty,forty,fifty,sixty,senventy,eighty,ninety
int main()
{
    int number;
    while(scanf("%d",&number)!=EOF)
    {
        if(number<=10)
        {
            if(number==0)
            {
                printf("zero\n");
            }
            else if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
            else if(number==10)
            {
            printf("ten\n");
            }
        }
        else if(number>10&&number<=20)
        {
            if(number==11)
            {
                printf("eleven\n");
            }
            else if(number==12)
            {
                printf("twelve\n");
            }
            else if(number==13)
            {
                printf("thirteen\n");
            }
            else if(number==14)
            {
                printf("fourteen\n");
            }
            else if(number==15)
            {
                printf("fifteen\n");
            }
            else if(number==16)
            {
                printf("sixteen\n");
            }
            else if(number==17)
            {
                printf("seventeen\n");
            }
            else if(number==18)
            {
                printf("eighteen\n");
            }   
            else if(number==19)
            {
                printf("nineteen\n");
            }
            else if(number==20)
            {
                printf("twenty\n");
            }
        }
        else if(number>20&&number<30)
        {
            printf("twenty-");
            number=number%20;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number>=30&&number<40)
        {
            printf("thirty-");
            number=number%30;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==30)
        {
            printf("thirty\n");
        }
        else if(number>30&&number<40)
        {
            printf("thirty-");
            number=number%30;

            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==40)
        {
            printf("forty\n");
        }
        else if(number>40&&number<50)
        {
            printf("forty-");
            number=number%40;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==50)
        {
            printf("fifty\n");
        }
        else if(number>50&&number<60)
        {
            printf("fifty-");
            number=number%50;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==60)
        {
            printf("sixty\n");
        }
        else if(number>60&&number<70)
        {
            printf("sixty-");
            number=number%60;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==70)
        {
            printf("seventy\n");
        }
        else if(number>70&&number<80)
        {
            printf("seventy-");
            number=number%70;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==80)
        {
            printf("eighty\n");
        }
        else if(number>80&&number<90)
        {
            printf("eighty-");
            number=number%80;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        else if(number==90)
        {
            printf("ninety\n");
        }
        else if(number>90&&number<100)
        {
            printf("ninety-");
            number=number%40;
            if(number==1)
            {
                printf("one\n");
            }
            else if(number==2)
            {
                printf("two\n");
            }
            else if(number==3)
            {
                printf("three\n");
            }
            else if(number==4)
            {
                printf("four\n");
            }
            else if(number==5)
            {
                printf("five\n");
            }
            else if(number==6)
            {
                printf("six\n");
            }
            else if(number==7)
            {
                printf("seven\n");
            }   
            else if(number==8)
            {
                printf("eight\n");
            }
            else if(number==9)
            {
                printf("nine\n");
            }
        }
        
    }
    return 0;
}
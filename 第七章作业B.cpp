#include<bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    double course1;
    double course2;
    double course3;
    double average;
}arr[10];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].name;
            scanf("%lf%lf%lf",&arr[i].course1,&arr[i].course2,&arr[i].course3);
            arr[i].average=(arr[i].course1+arr[i].course2+arr[i].course3)/3;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j].average<arr[j+1].average)
                {
                    swap(arr[j].average,arr[j+1].average);
                    swap(arr[j].course1,arr[j+1].course1);
                    swap(arr[j].course2,arr[j+1].course2);
                    swap(arr[j].course3,arr[j+1].course3);
                    swap(arr[j].name,arr[j+1].name);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i].name;
            printf(" %.2lf %.2lf %.2lf %.2lf\n",arr[i].course1,arr[i].course2,arr[i].course3,arr[i].average);
        }
    }
    return 0;
}
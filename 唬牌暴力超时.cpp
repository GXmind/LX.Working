#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t,k,m,num=1,x,y;
    char temp;
    int temp1=0;
    int temp2;
    vector<int>p;
    vector<int>p1;
    vector<int>p2;
    vector<int>p3;
    vector<int>p4;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<13;i++){
            scanf("%d",&k);
            p1.push_back(k);
        }
        for(int i=0;i<13;i++){
            scanf("%d",&k);
            p2.push_back(k);
        }
        for(int i=0;i<13;i++){
            scanf("%d",&k);
            p3.push_back(k);
        }
        for(int i=0;i<13;i++){
            scanf("%d",&k);
            p4.push_back(k);
        }
        sort(p1.begin(),p1.end());sort(p2.begin(),p2.end());
        sort(p3.begin(),p3.end());sort(p4.begin(),p4.end());
        scanf("%d",&m);
        while(m--) {
            getchar();
           temp=getchar();
            if ((char)temp=='S'&&num%4==1) {
                scanf("%d%d", &x, &y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                    temp2 = (lower_bound(p1.begin(), p1.end(), k) - p1.begin());
                    p1.erase(p1.begin() + temp2);
                }
                num++;
            }
            else if (temp=='!'&&num % 4 == 1) {
                scanf("%d",&y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p1.begin(), p1.end(), k) - p1.begin());
                    p1.erase(p1.begin() + temp2);
                }
                num++;
            }
            else if (temp=='?'&&num % 4 == 1) {
                for (auto it = p.end() - 1; it >= p.end() - y; it--) {
                    if (*it == x) {
                        temp1++;
                    }
                }
                if (temp1 == y) {
                        for (auto it = p.begin(); it < p.end(); it++) {
                            p1.push_back(*it);
                        }
                    }
                if (temp1 != y) {
                    for (auto it = p.begin(); it < p.end(); it++){
                                p4.push_back(*it);
                    }
                }
                sort(p1.begin(),p1.end());sort(p2.begin(),p2.end());
                sort(p3.begin(),p3.end());sort(p4.begin(),p4.end());
                p.clear();
                num++;
                temp1=0;
            }
            else if (temp=='s'&&num%4==2) {
                scanf("%d%d", &x, &y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p2.begin(), p2.end(), k) - p2.begin());
                    p2.erase(p2.begin() + temp2);
                }
                num++;
            }
            else if (temp=='!'&&num % 4 == 2) {
                scanf("%d",&y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p2.begin(), p2.end(), k) - p2.begin());
                    p2.erase(p2.begin() + temp2);
                }
                num++;
            }
            else if (temp=='?'&&num % 4 == 2) {
                for (auto it = p.end() - 1; it >= p.end() - y; it--) {
                    if (*it == x) {
                        temp1++;
                    }
                }
                if (temp1 == y) {
                    for (auto it = p.begin(); it < p.end(); it++) {
                        p2.push_back(*it);
                    }
                }
                if (temp1 != y) {
                    for (auto it = p.begin(); it < p.end(); it++){
                        p1.push_back(*it);
                    }
                }
                sort(p1.begin(),p1.end());sort(p2.begin(),p2.end());
                sort(p3.begin(),p3.end());sort(p4.begin(),p4.end());
                p.clear();
                num++;
                temp1=0;
            }
            else if (temp=='s'&&num%4==3) {
                scanf("%d%d", &x, &y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p3.begin(), p3.end(), k) - p3.begin());
                    p3.erase(p3.begin() + temp2);
                }
                num++;
            }
            else if (temp=='!'&&num % 4 == 3) {
                scanf("%d",&y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p3.begin(), p3.end(), k) - p3.begin());
                    p3.erase(p3.begin() + temp2);
                }
                num++;
            }
            else if (temp=='?'&&num % 4 == 3) {
                for (auto it = p.end() - 1; it >= p.end() - y; it--) {
                    if (*it == x) {
                        temp1++;
                    }
                }
                if (temp1 == y) {
                    for (auto it = p.begin(); it < p.end(); it++) {
                        p3.push_back(*it);
                    }
                }
                if (temp1 != y) {
                    for (auto it = p.begin(); it < p.end(); it++){
                        p2.push_back(*it);
                    }
                }
                sort(p1.begin(),p1.end());sort(p2.begin(),p2.end());
                sort(p3.begin(),p3.end());sort(p4.begin(),p4.end());
                p.clear();
                num++;
                temp1=0;
            }
            else if (temp=='s'&&num%4==0) {
                scanf("%d%d", &x, &y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p4.begin(), p4.end(), k) - p4.begin());
                    p4.erase(p4.begin() + temp2);
                }
                num++;
            }
            else if (temp=='!'&&num % 4 == 0) {
                scanf("%d",&y);
                for (int i = 0; i < y; i++) {
                    scanf("%d", &k);
                    p.push_back(k);
                     temp2 = (lower_bound(p4.begin(), p4.end(), k) - p4.begin());
                    p4.erase(p4.begin() + temp2);
                }
                num++;
            }
            else if (temp=='?'&&num % 4 == 0) {
                for (auto it = p.end() - 1; it >= p.end() - y; it--) {
                    if (*it == x) {
                        temp1++;
                    }
                }
                if (temp1 == y) {
                    for (auto it = p.begin(); it < p.end(); it++) {
                        p4.push_back(*it);
                    }
                }
                if (temp1 != y) {
                    for (auto it = p.begin(); it < p.end(); it++){
                        p3.push_back(*it);
                    }
                }
                sort(p1.begin(),p1.end());sort(p2.begin(),p2.end());
                sort(p3.begin(),p3.end());sort(p4.begin(),p4.end());
                p.clear();
                num++;
                temp1=0;
            }
        }
        for(auto it=p1.begin();it<p1.end();it++){
            if(it==p1.begin())
                printf("%d",*it);
            else
                printf(" %d",*it);
        }
        printf("\n");
        for(auto it=p2.begin();it<p2.end();it++){
            if(it==p2.begin())
                printf("%d",*it);
            else
                printf(" %d",*it);
        }
        printf("\n");
        for(auto it=p3.begin();it<p3.end();it++){
            if(it==p3.begin())
                printf("%d",*it);
            else
                printf(" %d",*it);
        }
        printf("\n");
        for(auto it=p4.begin();it<p4.end();it++){
            if(it==p4.begin())
                printf("%d",*it);
            else
                printf(" %d",*it);
        }
        printf("\n");
    }
}
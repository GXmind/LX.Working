#include<bits/stdc++.h>
#include<Windows.h>

using namespace std;
int cnt=0;
struct node {
	int ch[2];
} t[5001];
char base64_table[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string base64_encode(string str) {
	int len=str.length();
	string ans="";
	for (int i=0; i<len/3*3; i+=3) {
		ans+=base64_table[str[i]>>2];
		ans+=base64_table[(str[i]&0x3)<<4 | (str[i+1])>>4];
		ans+=base64_table[(str[i+1]&0xf)<<2 | (str[i+2])>>6];
		ans+=base64_table[(str[i+2])&0x3f];
	}
	if(len%3==1) {
		int pos=len/3*3;
		ans+=base64_table[str[pos]>>2];
		ans+=base64_table[(str[pos]&0x3)<<4];
		ans+="=";
		ans+="=";
	} else if(len%3==2) {
		int pos=len/3*3;
		ans+=base64_table[str[pos]>>2];
		ans+=base64_table[(str[pos]&0x3)<<4 | (str[pos+1])>>4];
		ans+=base64_table[(str[pos+1]&0xf)<<2];
		ans+="=";
	}
	return ans;
}

void Trie_build(int x) {
	int num[31]= {0};
	for(int i=30; i>=0; i--) {
		if(x&(1<<i))num[i]=1;
		else num[i]=0;
	}
	int now=0;
	for(int i=30; i>=0; i--) {
		if(!t[now].ch[num[i]])
			t[now].ch[num[i]]=++cnt;
		now=t[now].ch[num[i]];
	}
}

int Trie_query(int x) {
	int now=0,ans=0;
	for(int i=30; i>=0; i--) {
		if((1<<i)&x) {
			if(t[now].ch[0]) {
				ans|=(1<<i);
				now=t[now].ch[0];
			} else
				now=t[now].ch[1];
		}
		if(!((1<<i)&x)) {
			if(t[now].ch[1]) {
				ans|=(1<<i);
				now=t[now].ch[1];
			} else
				now=t[now].ch[0];
		}
	}
	return ans;
}


int c[]= {35291831,12121212,14515567,25861240,12433421,53893532,13249232,34982733,23424798,98624870,87624276};
//string flag="WhatisYourStory";
// number = 34982733
int main() {
	
	cout<<"Hi, I want to know:";
	string s;cin>>s;
	
	
	DWORD oldProtect; 
    VirtualProtect((LPVOID)&Trie_build, sizeof(&Trie_build), PAGE_EXECUTE_READWRITE, &oldProtect);
    
	char *a = (char *)Trie_build;
	char *b = (char *)Trie_query;
	int i=0;
    
	for(; a<b; a++){
		*((BYTE*)a )^=0x20;
	}
	
	int opt=89149889;
	for(int i=1; i<=10; i++)Trie_build(c[i]);
	int x=Trie_query(opt),number;
	cout<<"你能猜出树上哪个值与89149889得到了随机种子吗"<<endl;
	cin>>number;
	
	srand(x);
	random_shuffle(base64_table,base64_table+64);
	
//	cout<<x<<endl;
//	cout<<base64_table<<endl; 
//	cout<<base64_encode(s)<<endl;
	
	string ss=base64_encode(s);
	if(ss=="fagg4lvhss7qjvBC0FJr")
		cout<<"good!let your story begin:flag{"<<s<<number<<"}"<<endl;
	else cout<<"try and try again"<<endl;
	return 0;
	
	/*cout<<Trie_query(opt)<<endl;
	cout<<endl;
	for(int i=0;i<=10;i++){
		cout<<(opt^c[i])<<endl;
	}*/


	return 0;
}

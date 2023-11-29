#include <iostream>
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

constexpr long long int MOD=1e9+7,N=1e5+10;

struct assignment{
	ll index;
	ll extra;
	
}w[N];

bool cmp(const assignment&a,const assignment&b){
	
	return b.index*(a.index+a.extra)+b.extra>a.index*(b.index+b.extra)+a.extra;
	
}
void pre(ll t){
	for(ll i=0;i<t;i++){
		scanf("%lld%lld",&w[i].index,&w[i].extra);
		
	}
	sort(w,w+t,cmp);
	
}

ll fastTimes(ll x,ll y,ll z,ll mod){
	ll ans=0;
	while(y){
		if(y&1){
			
			ans=(ans+x)%mod;
		}
		x=x*2%mod;
		y/=2;//y>>=1
		
	}
	ans=(ans+z)%mod;
	
	return ans;
}
int main() {
	ll T;
	while(~scanf("%lld",&T)){
		pre(T);
		ll sum=1;
	for(ll i=0;i<T;i++){
			sum=fastTimes(sum,w[i].index%MOD,w[i].extra,MOD);
		}
		printf("%lld\n",sum);
		
	}	
	
	
	
	
	
	return 0;
}

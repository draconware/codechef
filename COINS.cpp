#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL,LL> m;

LL dp(LL n){
	if(m[n] != 0){
		return m[n];
	}
	if(n < (n/2)+(n/3)+(n/4)){
		m[n] = dp(n/2)+dp(n/3)+dp(n/4);
		return m[n];
	}else{
		m[n]=n;
		return n;
	}
}

int main(){
	LL n;
	while(scanf("%lld", &n) != EOF){
		cout<<dp(n)<<endl;
	}
	return 0;
}
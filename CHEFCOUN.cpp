#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		LL n;
		cin>>n;

		LL na = (4294967296)%(n+1);
		na--;
		LL nb = n-na;

		LL b = (4294967296)/(n+1);
		LL a = b+1;

		for(LL i=0;i<na;i++){cout<<a<<" ";}
		for(LL j=0;j<nb;j++){cout<<b<<" ";}
		cout<<endl;
	}
}
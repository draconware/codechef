#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL M = (LL)(1e9 + 7);
LL inv = 111111112;

LL f(LL x,int y){
	LL res = 1;
	while(y>0){
		if(y&1){res = (res*x)%M;}
		y/=2;
		x = (x*x)%M;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		if()

	}
}
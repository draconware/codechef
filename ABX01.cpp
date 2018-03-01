#include<bits/stdc++.h>
using namespace std;

#define LL long long

int solve(LL a,LL n){
	int res=1;
	while(n>0){
		if(n&1){
			res = (res*a)%9 + 9*((res*a)%9 == 0);
		}
		n/=2;
		a = (a*a)%9 + 9*((a*a)%9 == 0);
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
		LL n,a;
		cin>>a>>n;

		a = (a%9) + 9*(a%9==0);
		cout<<solve(a,n)<<endl;
	}
}
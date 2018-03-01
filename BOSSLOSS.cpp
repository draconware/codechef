#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;

	while(t--){
		long long n,m;
		cin>>n>>m;

		long double m1 = (long double)m;
		long double n1 = -1+sqrt(8.0*m1);
		n1 = (n1/2.0);

		long long ans = (long long)ceil(n1);
		if(ans<=n){cout<<ans<<endl;}
		else{cout<<"-1"<<endl;}
	}
	return 0;
}
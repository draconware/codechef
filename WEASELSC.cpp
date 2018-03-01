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
		int n,k;
		LL ans=1000000;
		cin>>n>>k;
		LL x;

		for(int i=0;i<n;i++){
			cin>>x;
			ans=min(ans,x);
		}
		ans = ans*((LL)n);
		cout<<ans<<endl;
	}
}
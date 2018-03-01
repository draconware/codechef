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
		LL n,a,ans=0;
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>a;
			ans = ans|a;
		}
		cout<<ans<<endl;
	}
}
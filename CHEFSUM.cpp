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
		int n;
		cin>>n;

		LL pre[n+9],suff[n+9],arr[n+1];
		pre[0]=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];pre[i] = pre[i-1] + arr[i];
		}
		suff[n+1]=0;
		for(int i=n;i>=1;i--){
			suff[i] = suff[i+1] + arr[i];
		}
		LL best = 1e12,x=n+1;
		for(int i=1;i<=n;i++){
			if(pre[i]+suff[i] < best){
				x=i;
				best = pre[i]+suff[i];
			}
		}
		cout<<x<<endl;
	}
	return 0;
}
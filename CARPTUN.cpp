#include<bits/stdc++.h>
using namespace std;

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

		long long arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		long long ans = 0;
		for(int i=0;i<n;i++){
			ans = max(ans,arr[i]);
		}

		long long c,d,s;
		cin>>c>>d>>s;

		ans = ans*(c-1);
		long double res = (long double)ans;
		printf("%.12LF\n",res);
	}
}
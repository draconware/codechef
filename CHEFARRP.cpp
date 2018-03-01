#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

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

		LL arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		LL ans = n;
		for(int i=0;i<n;i++){
			LL x=arr[i],y=arr[i];
			for(int j=i+1;j<n;j++){
				x=x*arr[j];y+=arr[j];
				if(x>50000000000){break;}
				if(x==y){ans++;}
			}
		}
		cout<<ans<<endl;
	}
}
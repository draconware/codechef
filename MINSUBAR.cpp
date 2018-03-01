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
		int n,d;
		cin>>n>>d;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		int ans = n+1;
		for(int i=0;i<n;i++){
			if(arr[i]>=d){ans=1;}
		}
		int prefix[n];
		prefix[0]=arr[0];
		for(int i=1;i<n;i++){
			prefix[i] = prefix[i-1]+arr[i];
		}
		for(int i=0;i<n;i++){
			if(prefix[i]>=d){ans = min(ans,i+1);}
		}
		multiset<pair<int,int> > mul;
		mul.insert(make_pair(prefix[0],0));

		for(int i=1;i<n;i++){
			while(!mul.empty()){
				pair<int,int> p = *mul.begin();
				if(prefix[i] - p.first < d){break;}
				else{
					ans = min(ans,i-p.second);
				}
				mul.erase(mul.begin());
			}
			mul.insert(make_pair(prefix[i],i));
		}
		if(ans == n+1){cout<<"-1"<<endl;}
		else{cout<<ans<<endl;}
	}
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long

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
		LL k;

		cin>>n>>k;
		LL arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}

		LL max1=LLONG_MIN;
		LL sum=0;
		for(int i=0;i<n;i++){
			sum+=arr[i];
			max1 = max(max1,sum);
			if(sum<0){
				sum=0;
			}
		}
		//cout<<max1<<endl;
		LL total=0;
		for(int i=0;i<n;i++){
			total+=arr[i];
		}
		LL ans = max1;
		if(total>0 && k>1){
			LL prefix=0;
			LL prefix_max=LLONG_MIN;
			for(int i=0;i<n;i++){
				prefix+=arr[i];
				prefix_max = max(prefix_max,prefix);
			}
			LL suffix=0;
			LL suffix_max=LLONG_MIN;
			for(int i=n-1;i>=0;i--){
				suffix+=arr[i];
				suffix_max = max(suffix_max,suffix);
			}
			LL max2 = (k-2)*total + prefix_max + suffix_max;
			ans = max(ans,max2);
		}else if(total<=0 && k>1){
			LL prefix=0;
			LL prefix_max=LLONG_MIN;
			for(int i=0;i<n;i++){
				prefix+=arr[i];
				prefix_max = max(prefix_max,prefix);
			}
			LL suffix=0;
			LL suffix_max=LLONG_MIN;
			for(int i=n-1;i>=0;i--){
				suffix+=arr[i];
				suffix_max = max(suffix_max,suffix);
			}
			LL max2;
			if(prefix_max>0 && suffix_max>0){max2 = prefix_max + suffix_max;}
			else{max2 = max(prefix_max,suffix_max);}
			ans = max(ans,max2);
		}
		cout<<ans<<endl;
	}
}
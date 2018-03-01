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

		int arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];arr[i]%=4;}
		int even=0,odd1=0,odd2=0,odd=0,mini=0,sum=0;
		for(int i=0;i<n;i++){
			if(arr[i]==1){odd1++;}
			if(arr[i]==2){even++;}
			if(arr[i]==3){odd2++;}
			sum+=arr[i];
		}
		if(sum%4 == 0){
			int ans=0;
			mini = min(odd1,odd2);
			ans = ans+mini;
			odd = max(odd1-mini,odd2-mini);

			if(2*even >= odd){
				ans = ans + odd;
				even = even - (odd/2);
				ans = ans + (even/2);
			}else{
				ans = ans + 2*even;
				odd = odd - (2*even);
				ans = ans + (3*(odd/4));
			}
			cout<<ans<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100009];
int inf = (int)(1e7);

bool check(int i,int j){
	if(arr[i]>arr[j]){return true;}
	return false;
}

int flip(int i){
	return (n-i-1);
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
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		if(n==1){cout<<"0"<<endl;continue;}

		int dp[n+1][2];
		for(int i=0;i<=n;i++){
			dp[i][0] = dp[i][1] = inf;
		}
		dp[0][0] = 0;
		dp[0][1] = 1;

		for(int i=1;i<n;i++){
			if(i%2 == 1){
				if(check(i-1,i)){
					dp[i][0] = min(dp[i][0],dp[i-1][0]);
				}
				if(flip(i-1) == i){
					if(check(flip(i-1),flip(i))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i-1),i)){
					dp[i][0] = min(dp[i][0],dp[i-1][1]);
				}
				if((i-1)==flip(i)){
					if(check(flip(i-1),flip(i))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(i-1,flip(i))){
					dp[i][1] = min(dp[i][1],1+dp[i-1][0]);
				}
				if(i == flip(i-1)){
					if(check(flip(i-1),flip(i))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i-1),flip(i))){
					dp[i][1] = min(dp[i][1],1+dp[i-1][1]);
				}
			}else{
				if(check(i,i-1)){
					dp[i][0] = min(dp[i][0],dp[i-1][0]);
				}
				if(flip(i-1) == i){
					if(check(flip(i),flip(i-1))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(i,flip(i-1))){
					dp[i][0] = min(dp[i][0],dp[i-1][1]);
				}
				if((i-1)==flip(i)){
					if(check(flip(i),flip(i-1))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i),i-1)){
					dp[i][1] = min(dp[i][1],1+dp[i-1][0]);
				}
				if(i == flip(i-1)){
					if(check(flip(i),flip(i-1))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i),flip(i-1))){
					dp[i][1] = min(dp[i][1],1+dp[i-1][1]);
				}
			}
		}
		int ans1 = min(dp[n-1][0],dp[n-1][0]);

		for(int i=0;i<=n;i++){
			dp[i][0] = dp[i][1] = inf;
		}
		dp[0][0] = 0;
		dp[0][1] = 1;

		for(int i=1;i<n;i++){
			if(i%2 == 0){
				if(check(i-1,i)){
					dp[i][0] = min(dp[i][0],dp[i-1][0]);
				}
				if(flip(i-1) == i){
					if(check(flip(i-1),flip(i))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i-1),i)){
					dp[i][0] = min(dp[i][0],dp[i-1][1]);
				}
				if((i-1)==flip(i)){
					if(check(flip(i-1),flip(i))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(i-1,flip(i))){
					dp[i][1] = min(dp[i][1],1+dp[i-1][0]);
				}
				if(i == flip(i-1)){
					if(check(flip(i-1),flip(i))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i-1),flip(i))){
					dp[i][1] = min(dp[i][1],1+dp[i-1][1]);
				}
			}else{
				if(check(i,i-1)){
					dp[i][0] = min(dp[i][0],dp[i-1][0]);
				}
				if(flip(i-1) == i){
					if(check(flip(i),flip(i-1))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(i,flip(i-1))){
					dp[i][0] = min(dp[i][0],dp[i-1][1]);
				}
				if((i-1)==flip(i)){
					if(check(flip(i),flip(i-1))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i),i-1)){
					dp[i][1] = min(dp[i][1],1+dp[i-1][0]);
				}
				if(i == flip(i-1)){
					if(check(flip(i),flip(i-1))){
						dp[i][1] = min(dp[i][1],dp[i-1][1]);
					}
				}else if(check(flip(i),flip(i-1))){
					dp[i][1] = min(dp[i][1],1+dp[i-1][1]);
				}
			}
		}
		int ans2 = min(dp[n-1][0],dp[n-1][1]);
		int ans = min(ans1,ans2);
		if(ans >= inf){cout<<"-1"<<endl;}
		else{cout<<ans<<endl;}
	}
}
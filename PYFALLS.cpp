#include<bits/stdc++.h>
using namespace std;

#define LL long long 
LL MAX = (LL)1e18;

LL x,y;
double c;
double dp[2005][2005];

bool chk(LL w){
	if(w-c<0){return false;}
	dp[1][1] = (double)w - c;

	if(x==1 && y==1){return true;}
	for(int i=2;i<2005;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])/2.0;
			dp[i][j] -= c;
			if(i==x && j==y){
				if(dp[i][j]<0){return false;}
				else{return true;}
			}
			dp[i][j] = max(0.0,dp[i][j]);
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>x>>y>>c;
		memset(dp,0.0,sizeof(dp));

		LL l=0,h=MAX,ans=-1;
		while(l<=h){
			LL m = (l+h)/2;
			if(chk(m)){
				ans = m;
				h=m-1;
			}else{
				l=m+1;
			}
		}
		cout<<ans<<endl;
	}
}
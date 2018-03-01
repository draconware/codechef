#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y){
	int n = (int)x.length();
	int m = (int)y.length();

	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i-1]==y[j-1]){dp[i][j] = dp[i-1][j-1]+1;}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[n][m];
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
		int n,m;
		cin>>n>>m;

		string a,b;
		cin>>a>>b;

		int len = (int)a.length();
		string x;
		for(int i=1;i<len;i++){
			if(a[i-1]!=a[i]){x.push_back(a[i-1]);}
		}
		x.push_back(a[len-1]);

		len = (int)b.length();
		string y;
		for(int i=1;i<len;i++){
			if(b[i-1]!=b[i]){y.push_back(b[i-1]);}
		}
		y.push_back(b[len-1]);

		n = (int)x.length();
		m = (int)y.length();

		int ans = (n+m-1)-(lcs(x,y))+1;
		cout<<ans<<endl;
	}
}
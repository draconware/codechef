#include<bits/stdc++.h>
using namespace std;

#define LL long long

int n,p,q,b1,b2,s1,s2;
LL dp[55][55][55][55][3];
LL M = (LL)(1e9+7);

LL f(int i,int j,int x,int y,int type){
	//cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<type<<endl;
	if(i+j>=n){
		if((i+j)==n){return 1;}
		else{return 0;}
	}
	if(dp[i][j][x][y][type]!=-1){return dp[i][j][x][y][type];}
	LL sum=0;
	//cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;

	if(i<p && x<b1 && (type==0 || type==2)){
		for(int k=1;k<=s1 && (i+k<=p);k++){
			sum = (sum + f(i+k,j,x+1,y,1))%M;
		}
	}
	if(j<q && y<b2 && (type==0 || type==1)){
		for(int k=1;k<=s2 && (j+k<=q);k++){
			sum = (sum + f(i,j+k,x,y+1,2))%M;
		}
	}
	dp[i][j][x][y][type] = sum;
	return sum;
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
		memset(dp,-1,sizeof(dp));
		cin>>p>>q>>n>>b1>>b2>>s1>>s2;

		LL ans = f(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
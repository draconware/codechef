#include<bits/stdc++.h>
using namespace std;

#define MAX 111
#define M 1000000007

int val[MAX][MAX][MAX];
int arr[MAX];
int shift=51,n;

int dp(int pos,int prev,int nxt){
	if(arr[pos]+prev<0 || arr[pos+1]+nxt<0){return 0;}
	if(pos>=n && (arr[pos]+prev)*(arr[pos+1]+nxt)==0){return 1;}
	int ans = val[pos][prev+shift][nxt+shift];
	if(ans != -1){return ans;}
	ans=0;
	for(int i=0;i<=min(arr[pos]+prev,arr[pos+1]+nxt);i++){
		ans+=dp(pos+1,nxt-i,i);
		ans%=M;
	}
	val[pos][prev+shift][nxt+shift]=ans;
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		cin>>n;

		memset(val,-1,sizeof(val));
		memset(arr,0,sizeof(arr));
		for(int i=1;i<=n;i++){cin>>arr[i];}
		cout<<dp(1,0,0)<<endl;
	}
}
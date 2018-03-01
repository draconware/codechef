#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL inf = (LL)(1e12);
int n;
string s;
LL dp[1003][3][1003];

LL f(int i,int side,int bullets){
	if(bullets<0){return inf;}
	if(i==n-1){
		return 0;
	}
	if(dp[i][side][bullets]!=-1){return dp[i][side][bullets];}

	LL sum=inf;
	if(side==0){
		if(s[i+1]=='#'){
			sum = min(sum,4+f(i+1,1,bullets));
			sum = min(sum,1+f(i+1,0,bullets-1));
		}else{
			sum = min(sum,1+f(i+1,0,bullets));
		}
	}else if(side==1){
		if(s[i]=='#'){
			sum = min(sum,2+f(i+1,1,bullets));
		}else{
			sum = min(sum,2+f(i,2,bullets));
			sum = min(sum,2+f(i+1,1,bullets));
		}
	}else if(side==2){
		if(s[i+1]=='#'){
			sum = min(sum,1+f(i+1,0,bullets-1));
		}else{
			sum = min(sum,1+f(i+1,0,bullets));
		}
	}
	dp[i][side][bullets] = sum;
	return sum;
}

int main(){
	int t;
	cin>>t;

	while(t--){f
		int b;
		cin>>n>>b>>s;

		LL ans = f(0,0,b);
		if(ans >= inf){cout<<"Impossible"<<endl;}
		else{cout<<ans<<endl;}
	}
}
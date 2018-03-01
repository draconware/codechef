#include<bits/stdc++.h>
using namespace std;

int power(int x,int y,int m){
	int res=1;
	while(y){
		if(y&1){res = (res*x)%m;}
		y/=2;
		x = (x*x)%m;
	}
	return res;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m,ans;
		cin>>n>>m;
		ans=1%m;
		for(int i=1;i<=n;i++){
			if(i%m == 0){continue;}
			ans = ans+power(i,i,m);
			ans%=m;
		}
		cout<<ans<<endl;
	}
}
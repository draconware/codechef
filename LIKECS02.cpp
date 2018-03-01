#include<bits/stdc++.h>
using namespace std;

#define LL long long

int n;

bool f(int m){
	LL t=0;
	if(n%2==1){
		//LL t=0;
		t = 2*(2*m-1);
		for(int i=4;i<=n;i+=2){
			t += i*(4*m-2*n-3);
		}
		for(int i=2;i<=n/2;i++){t-=(m-n+i-1);}
		t-=((m-n+(n/2+1)-1)/2);
	}else{
		for(int i=2;i<=n;i+=2){
			t += i*(4*m-2*n+1);
		}
	}
	if((t>=(n*n*n - n)) && (t<=(n*n*n + 2*n*n + n))){
		return true;
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
		//int n;
		cin>>n;

		int l=1,r=1e9,ans=-1;
		while(l<=r){
			int m = (l+r)/2;
			if(f(m)){
				l=m+1;
				ans=m;
			}else{
				r=m-1;
			}
		}
		if(ans==-1){cout<<ans<<endl;}
		if(n%2==0){
			for(int i=1;i<=n;i++){cout<<ans-n+i<<" ";}cout<<endl;
		}else{
			for(int i=1;i<=n;i++){cout<<ans-n+i-1<<" ";}cout<<endl;
		}
	}
}
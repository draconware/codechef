#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		LL n,k;
		cin>>n>>k;n-=k;

		LL a = n+k-1,b = k-1;
		if(b > (a/2)){b = a-b;}
		LL x=1;
		//cout<<a<<","<<b<<endl;
		for(LL i=1;i<=b;i++){
			x = x*(a-i+1);
			x/=i;
		}
		cout<<x<<endl;
	}
	return 0;
}
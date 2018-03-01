#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long
LL M = 1000000009;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL arr[n+1];
		LL val[n+1];
		memset(val,0,sizeof(val));
		for(int i=0;i<=n;i++){cin>>arr[i];}
		val[0]=arr[0];
		for(int i=1;i<=n;i++){
			val[i] = (val[i-1]+arr[i])%M;
		}
		LL a=0,b;
		for(int i=1;i<=n;i++){
			b = (2*a)%M + (2*arr[i]*val[i-1])%M;
			a = b;
		}
		cout<<a<<endl;
	}
	return 0;
}
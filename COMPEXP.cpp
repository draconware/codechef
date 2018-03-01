#include<bits/stdc++.h>
using namespace std;

#define LL long double

int main(){
	int t;cin>>t;

	while(t--){
		LL n,k;
		cin>>n>>k;

		LL ans = 2.0*(1.0 + ((n-1)*(k-1))/k);
		printf("%.Lf\n",ans);
	}
}
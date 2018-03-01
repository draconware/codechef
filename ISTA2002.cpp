#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL mod = 1e9+7;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		LL n,l,b,h;
		cin>>n>>l>>b>>h;

		LL x[n],y[n],z[n];
		for(LL i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		sort(x,x+n);sort(y,y+n);sort(z,z+n);

		LL max_x=x[0],max_y=y[0],max_z=z[0];
		for(LL i=1;i<n;i++){
			max_x = max(max_x,x[i]-x[i-1]);
			max_y = max(max_y,y[i]-y[i-1]);
			max_z = max(max_z,z[i]-z[i-1]);
		}
		//cout<<max_x<<" "<<max_y<<" "<<max_z<<endl;
		max_x = max(max_x,l-x[n-1]);
		max_y = max(max_y,b-y[n-1]);
		max_z = max(max_z,h-z[n-1]);
		//cout<<max_x<<" "<<max_y<<" "<<max_z<<endl;

		cout<<(((max_x*max_y)%mod)*max_z)%mod<<endl;
	}
}
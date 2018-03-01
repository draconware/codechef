#include<bits/stdc++.h>
using namespace std;

#define LL long long

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
		LL x,y;
		cin>>x>>y;

		LL p,q;
		cin>>p>>q;

		x = abs(x-p);
		y = abs(y-q);

		LL a = min(x,y);
		LL b = max(x,y);

		LL ans = 2*a;
		b-=a;
		ans = ans + b;
		b/=2;
		ans = ans + 2*b;
		cout<<ans<<endl;
	}
	return 0;
}
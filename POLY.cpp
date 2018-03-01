#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,q;
		cin>>n;

		pair<pair<LL,LL>,pair<LL,LL> > v;
		for(int i=0;i<n;i++){
			LL a,b,c,d;cin>>a>>b>>c>>d;
			v.push_back(make_pair(make_pair(a,b),make_pair(c,d)));
		}

		cin>>q;
		while(q--){
			LL x;cin>>x;
			LL ans = (LL)1e19;
			for(int i=0;i<n;i++){
				LL temp=0;
				temp = v[i].first.first + (t)*(v[i].first.second) + (t*t)(v[i].second.first) + (t*t*t)(v[i].second.second);
				ans = min(ans,temp);
			}
			cout<<ans<<endl;
		}
	}
}
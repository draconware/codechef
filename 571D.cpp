#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<pair<int,pair<LL,int> > > G[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,c;
	cin>>n>>m>>c;

	for(int i=0;i<m;i++){
		int a,b,co;
		LL w;
		cin>>a>>b>>w>>co;
		G[a].push_back(make_pair(b,make_pair(w,co)));
	}

	int s,q;
	cin>>s>>q;

	LL dist[n+1];
	for(int i=0;i<=n;i++){
		dist[i] = (LL)(1e18);
	}

	multiset<pair<int,int> > mul;
	mul.insert(make_pair(s,0));
	dist[s] = 0;

	while(!mul.empty()){
		pair<int,int> p = *mul.begin();
		mul.erase(mul.begin());

		int u = p.first;
		int co = p.second;

		for(int i=0;i<(int)G[u].size();i++){
			int v = G[u][i].first;
			LL w = G[u][i].second.first;
			int nco = G[u][i].second.second;

			if(nco != co){
				if(dist[v] > dist[u]+w){
					dist[v] = dist[u]+w;
					mul.insert(make_pair(v,nco));
				}
			}
		}
	}

	while(q--){
		int x;
		cin>>x;

		if(dist[x]>=(LL)(1e18)){cout<<"-1"<<endl;}
		else{cout<<dist[x]<<endl;}
	}
}
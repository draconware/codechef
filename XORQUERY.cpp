#include<bits/stdc++.h>
using namespace std;

vector<int> G[100009];
int parent[100009];



int root(int x){
	while(x!=parent[x]){x=parent[x];}
	return x;
}

int unite(int u,int v,int w){
	int p = root(u);
	int q = root(v);
	int r = w^dist[u]^dist[v];
	if(p<q){
		dist[q]
	}
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,q;
		cin>>n>>q;
		for(int i=0;i<=n;i++){G[i].clear();parent[i]=i;}

		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		while(q--){
			int type;cin>>type;
			if(type==1){
				int u,v,w;
				cin>>u>>v>>w;

				if(root(u)!=root(v)){
					unite(u,v,w);
					cout<<"AC"<<endl;
				}else{
					if(query(u,v) == w){cout<<"AC"<<endl;}
					else{cout<<"WA"<<endl;}
				}
			}else{
				int u,v;
				cin>>u>>v;

				if(root(u) == root(v)){
					cout<<query(u,v)<<endl;
				}else{
					cout<<"-1"<<endl;
				}
			}
		}
	}
}
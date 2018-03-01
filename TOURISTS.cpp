#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
int in[100009],out[100009];
vector<pair<int,int> > edges,res;
bool mark[100009];

void dfs(int s){
	mark[s]=true;

	for(int i=0;i<v[s].size();i++){
		if(!mark[v[s][i]]){dfs(v[s][i]);}
	}
}

void DFS(int s){
	mark[s]=true;
	for(int i=0;i<v[s].size();i++){
		
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		edges.push_back(make_pair(x,y));
	}
	bool flag=true;
	dfs(1);

	for(int i=1;i<=n;i++){
		int x = v[i].size();
		if(x%2 != 0 || !mark[i]){flag=false;}
	}
	if(!flag){cout<<"NO"<<endl;}
	else{
		//for(int i=1;i<=n;i++){cout<<v[i].size()<<" ";}cout<<endl;
		cout<<"YES"<<endl;
		memset(mark,0,sizeof(mark));
		DFS(1);
	}
}
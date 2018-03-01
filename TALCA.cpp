#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 200009

vector<int> v[MAX];
bool mark[MAX];
vector<int> t(MAX,-1),p(MAX),level(MAX,-1);
int val;

void dfs_parent(int x){
	mark[x]=true;
	for(int i=0;i<v[x].size();i++){
		if(mark[v[x][i]]){continue;}
		t[v[x][i]] = x;
		level[v[x][i]]=level[x]+1;
		dfs_parent(v[x][i]);
	}
}

void dfs(int x){
	mark[x]=true;
	if(level[x] < val){p[x]=1;}
	else if(level[x] == x){p[x]=t[x];}
	else{p[x] = p[t[x]];}

	for(int i=0;i<v[x].size();i++){
		if(!mark[v[x][i]]){
			dfs(v[x][i]);
		}
	}

}

int lca(int x,int y){
	while(p[x] != p[y]){
		if(level[x] < level[y]){
			y=p[y];
		}else{
			x=p[x];
		}
	}
	while(x!=y){
		if(level[x] < level[y]){
			y=t[y];
		}else{
			x=t[x];
		}
	}
	return x;
}

int main(){
	int n,x,y;
	cin>>n;

	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	val = (int)sqrt(n);
	memset(mark,0,sizeof(mark));
	dfs_parent(1);
	memset(mark,0,sizeof(mark));
	dfs(1);

	int q,r,u,v;
	cin>>q;

	while(q--){
		cin>>r>>u>>v;
		int x1=lca(r,u);
		int x2=lca(r,v);
		int x3=lca(u,v);

		if(x1==x2){cout<<x3<<endl;}
		else if(x1==x3){cout<<x2<<endl;}
		else{cout<<x1<<endl;}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[100009];
int start[100009],finish[100009];
int t=0;
pair<pair<LL,LL>,LL > st[100009];

void build(int s,int e,int )

void dfs(int s,int p){
	start[s]=t;
	for(int i=0;i<G[s].size();i++){
		int v = G[s][i];
		if(v!=p){
			t++;dfs(v);
		}
	}
	finish[s]=t;
}



int main(){
	int n,q;
	cin>>n>>q;

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	for(int i=2;i<=n;i++){
		int a;cin>>a;
		G[a].push_back(i);
	}
	dfs(1,0);

	build(0,n-1,0);
}
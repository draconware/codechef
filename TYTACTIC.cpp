#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<int> G[100009];
int start[100009],finish[100009],order[100009];
int vis[100009];
LL arr[100009],st[4*100009];
int t=0;

void dfs(int s,int p){
	vis[s]=t;
	order[t]=s;
	start[s]=t;
	for(int i=0;i<G[s].size();i++){
		int v = G[s][i];
		if(v!=p){t++;dfs(v,s);}
	}
	finish[s]=t;
}

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		st[idx] = arr[order[s]];
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx+1);
	build(m+1,e,2*idx+2);
	st[idx] = st[2*idx+1]+st[2*idx+2];
}

void update(int s,int e,int p,LL val,int idx){
	if(p<s || p>e){return ;}
	if(s==e && s==p){
		st[idx] = val;
		return ;
	}
	int m = (s+e)/2;
	update(s,m,p,val,2*idx+1);
	update(m+1,e,p,val,2*idx+2);
	st[idx] = st[2*idx+1]+st[2*idx+2];
}

LL query(int s,int e,int l,int r,int idx){
	if(s>r || l>e){return 0;}
	if(l<=s && r>=e){return st[idx];}

	int m = (s+e)/2;
	LL left = query(s,m,l,r,2*idx+1);
	LL right = query(m+1,e,l,r,2*idx+2);
	return (left+right);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,q;
	cin>>n>>q;

	for(int i=1;i<=n;i++){cin>>arr[i];}

	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1,0);
	
	build(0,n-1,0);
	while(q--){
		char c;
		cin>>c;

		if(c=='Q'){
			int x;cin>>x;
			cout<<query(0,n-1,start[x],finish[x],0)<<endl;
		}else{
			int x;LL y;cin>>x>>y;
			update(0,n-1,vis[x],y,0);
		}
	}
}
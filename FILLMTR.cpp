#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int,int> > v[100009];
 
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
		int n,k;
		cin>>n>>k;
 
		for(int i=0;i<=n;i++){v[i].clear();}
		for(int i=0;i<k;i++){
			int a,b,c;
			cin>>a>>b>>c;
			v[a].push_back(make_pair(b,c));
		}
		int level[n+1];
		memset(level,-1,sizeof(level));
		bool mark[n+1],flag=true;
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=n;i++){
			if(!mark[i]){
				queue<int> q;
				q.push(i);
				level[i]=0;
				mark[i]=true;
				while(!q.empty()){
					int x = q.front();q.pop();
					for(int i=0;i<(int)v[x].size();i++){
						if(!mark[v[x][i].first]){
							mark[v[x][i].first]=true;
							level[v[x][i].first] = (level[x]+v[x][i].second)%2;
							q.push(v[x][i].first);
						}else{
							if(level[v[x][i].first] != (level[x]+v[x][i].second)%2){flag=false;break;}
						}
					}
					if(!flag){break;}
				}
			}
			if(!flag){break;}
		}
		if(flag){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}
}
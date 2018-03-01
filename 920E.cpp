#include<bits/stdc++.h>
using namespace std;

set<int> G[200009];
set<int> unmark;
vector<int> connected_size;

void bfs(int s){
	unmark.erase(s);
	int c=0;
	queue<int> q;
	q.push(s);
	
	while(!q.empty()){
		int u = q.front();q.pop();
		c++;
		vector<int> v;
		for(set<int>::iterator it = unmark.begin();unmark.end();it++){
			if(G[u].find(*it) == G[u].end()){
				v.push_back(*it);
			}
		}
		for(int i=0;i<(int)v.size();i++){
			unmark.erase(v[i]);
			q.push(v[i]);
		}
		v.clear();
	}
	connected_size.push_back(c);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a].insert(b);
		G[b].insert(a);
	}

	for(int i=1;i<=n;i++){
		unmark.insert(i);
	}

	for(int i=1;i<=n;i++){
		if(unmark.find(i) != unmark.end()){
			bfs(i);
		}
	}
	sort(connected_size.begin(),connected_size.end());
	cout<<connected_size.size()<<endl;
	for(int i=0;i<(int)connected_size.size();i++){
		cout<<connected_size[i]<<" ";
	}cout<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr[150000];
vector<int> G[150000];
LL min_elem[150000];
LL max_elem[150000];
LL lazy[150000];
LL child[150000];
bool mark[150000];

void dfs(int s){
	mark[s]=true;
	min_elem[s] = arr[s];lazy[s]=0;max_elem[s]=arr[s];
	child[s] = 1;
	if(s==0){return ;}
	
	int x = (int)floor(log2((float)s));
	int y = s;
	for(int j=x;j>=0;j--){
		x = (int)pow(2.0,j);
		int v = s&x;
		if(v>0 && !mark[v]){
			G[s].push_back(v);
			dfs(v);
			min_elem[s] = min(min_elem[s],min_elem[v]);
			max_elem[s] = max(max_elem[s],max_elem[v]);
			child[s] = child[s] + child[v];
		}
	}
}

LL query(int s,int x,LL y){
	LL ans=0;
	if(max_elem[s]<=0){return 0;}
	int a = s&x;
	if(a==s){
		lazy[s] = lazy[s]+y;
		if(lazy[s]<min_elem[s]){ans = ans + child[s];}
		else{
			arr[s]-=lazy[s];lazy[s]=0;
			if(arr[s]>0){ans = 1;}
			child[s] = ans;
			if(arr[s]>0){min_elem[s] = arr[s];}
			else{min_elem[s] = LLONG_MAX;}
			max_elem[s] = arr[s];
			for(int i=0;i<(int)G[s].size();i++){
				int v = G[s][i];
				ans = ans + query(v,x,y);
				min_elem[s] = min(min_elem[s],min_elem[v]);
				max_elem[s] = max(max_elem[s],max_elem[v]);
				child[s] = child[s] + child[v];
			}
		}
	}else if(a>0){
		if(arr[s]>0){ans = 1;}
		child[s] = ans;
		if(arr[s]>0){min_elem[s] = arr[s];}
		else{min_elem[s] = LLONG_MAX;}
		max_elem[s] = arr[s];
		for(int i=0;i<(int)G[s].size();i++){
			int v = G[s][i];
			ans = ans + query(v,x,y);
			min_elem[s] = min(min_elem[s],min_elem[v]);
			max_elem[s] = max(max_elem[s],max_elem[v]);
			child[s] = child[s] + child[v];
		}
	}else{
		ans = ans + child[s];
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){cin>>arr[i];}
	vector<int> chk;

	for(int i=n-1;i>=0;i--){
		if(!mark[i]){
			dfs(i);
			chk.push_back(i);
		}
	}

	int q;
	cin>>q;

	while(q--){
		int x;LL y;
		cin>>x>>y;

		LL ans = 0;
		for(int i=0;i<(int)chk.size();i++){
			ans = ans + query(chk[i],x,y);
		}
		cout<<ans<<endl;
	}
	return 0;
}
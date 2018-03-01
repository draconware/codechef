#include<bits/stdc++.h>
using namespace std;

int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int n,m;

bool chk(int a,int b){
	if(a<0 || a>=n || b<0 || b>=m){return false;}
	return true;

}

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
		cin>>n>>m;

		int arr[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}

		int mark[n][m];
		memset(mark,0,sizeof(mark));

		int ans=0;
		priority_queue<pair<int,pair<int,int> > > v;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				v.push(make_pair(arr[i][j],make_pair(i,j)));
			}
		}
		while(!v.empty()){
			int u1 = v.top().second.first;
			int v1 = v.top().second.second;
			//cout<<"evaluating "<<u1<<","<<v1<<"----- "<<endl;
			v.pop();
			if(!mark[u1][v1]){
				mark[u1][v1]=true;
				ans++;
				queue<pair<int,int> > q;
				q.push(make_pair(u1,v1));
				
				while(!q.empty()){
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					//cout<<a<<","<<b<<endl;

					for(int i=0;i<4;i++){
						int na = a+x[i],nb = b+y[i];
						if(chk(na,nb) && !mark[na][nb]){
							if(arr[na][nb]<=arr[a][b]){
								mark[na][nb]=true;
								q.push(make_pair(na,nb));
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;

struct  node{
	int f,s;
};

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		int pf[n][m];
		int pt[n][m];
		struct node level[n][m];

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>pf[i][j];level[i][j].f=INT_MAX;level[i][j].s=INT_MAX;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>pt[i][j];
			}
		}
		bool mark[n][m];
		memset(mark,0,sizeof(mark));
		multiset<pair<pair<int,int>,pair<int,int> > > q;
		q.insert(make_pair(make_pair(pf[0][0],pt[0][0]),make_pair(0,0)));
		level[0][0].f=pf[0][0];level[0][0].s=pt[0][0];

		while(!q.empty()){
			pair<pair<int,int>,pair<int,int> > p = *q.begin();q.erase(q.begin());
			int w1=p.first.first,w2=p.first.second,x=p.second.first,y=p.second.second;
			if(mark[x][y]){continue;}
			//cout<<x<<","<<y<<" "<<w1<<","<<w2<<endl;
			//if(x==n-1 && y==m-1){cout<<w1<<" "<<w2<<endl;}
			mark[x][y]=true;

			if(x-1>=0 && !mark[x-1][y]){
				//cout<<"executed"<<" ";
				if((level[x-1][y].f > level[x][y].f + pf[x-1][y])){
					level[x-1][y].f = level[x][y].f + pf[x-1][y];
					level[x-1][y].s = level[x][y].s + pt[x-1][y];
					q.insert(make_pair(make_pair(level[x-1][y].f,level[x-1][y].s),make_pair(x-1,y)));
				}else if((level[x-1][y].f == level[x][y].f + pf[x-1][y])&&(level[x-1][y].s > level[x][y].s + pt[x-1][y])){
					level[x-1][y].f = level[x][y].f + pf[x-1][y];
					level[x-1][y].s = level[x][y].s + pt[x-1][y];
					q.insert(make_pair(make_pair(level[x-1][y].f,level[x-1][y].s),make_pair(x-1,y)));
				}
			}
			if(x+1<n && !mark[x+1][y]){
				//cout<<"executed"<<" ";
				if((level[x+1][y].f > level[x][y].f + pf[x+1][y])){
					level[x+1][y].f = level[x][y].f + pf[x+1][y];
					level[x+1][y].s = level[x][y].s + pt[x+1][y];
					q.insert(make_pair(make_pair(level[x+1][y].f,level[x+1][y].s),make_pair(x+1,y)));
				}else if((level[x+1][y].f == level[x][y].f + pf[x+1][y])&&(level[x+1][y].s > level[x][y].s + pt[x+1][y])){
					level[x+1][y].f = level[x][y].f + pf[x+1][y];
					level[x+1][y].s = level[x][y].s + pt[x+1][y];
					q.insert(make_pair(make_pair(level[x+1][y].f,level[x+1][y].s),make_pair(x+1,y)));
				}
			}
			if(y-1>=0 && !mark[x][y-1]){
				//cout<<"executed"<<" ";
				if((level[x][y-1].f > level[x][y].f + pf[x][y-1])){
					level[x][y-1].f = level[x][y].f + pf[x][y-1];
					level[x][y-1].s = level[x][y].s + pt[x][y-1];
					q.insert(make_pair(make_pair(level[x][y-1].f,level[x][y-1].s),make_pair(x,y-1)));
				}else if((level[x][y-1].f == level[x][y].f + pf[x][y-1])&&(level[x][y-1].s > level[x][y].s + pt[x][y-1])){
					level[x][y-1].f = level[x][y].f + pf[x][y-1];
					level[x][y-1].s = level[x][y].s + pt[x][y-1];
					q.insert(make_pair(make_pair(level[x][y-1].f,level[x][y-1].s),make_pair(x,y-1)));
				}
			}
			if(y+1<m && !mark[x][y+1]){
				//cout<<"executed"<<" ";
				if((level[x][y+1].f > level[x][y].f + pf[x][y+1])){
					level[x][y+1].f = level[x][y].f + pf[x][y+1];
					level[x][y+1].s = level[x][y].s + pt[x][y+1];
					q.insert(make_pair(make_pair(level[x][y+1].f,level[x][y+1].s),make_pair(x,y+1)));
				}else if((level[x][y+1].f == level[x][y].f + pf[x][y+1])&&(level[x][y+1].s > level[x][y].s + pt[x][y+1])){
					level[x][y+1].f = level[x][y].f + pf[x][y+1];
					level[x][y+1].s = level[x][y].s + pt[x][y+1];
					q.insert(make_pair(make_pair(level[x][y+1].f,level[x][y+1].s),make_pair(x,y+1)));
				}
			}
		//	cout<<endl;
		}
		
		cout<<level[n-1][m-1].f<<" "<<level[n-1][m-1].s<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
vector<int> G[100009];
 
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
		for(int i=0;i<100009;i++){G[i].clear();}
		int n;
		cin>>n;
 
		double cost[n+1];
		for(int i=1;i<=n;i++){cin>>cost[i];}
 
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
 
		multiset<pair<double,pair<int,int> > > mul;
		for(int i=1;i<=n;i++){
			mul.insert(make_pair(cost[i],make_pair(i,i)));
		}
 
		pair<double,int> val[n+1];
		for(int i=1;i<=n;i++){
			val[i] = make_pair(cost[i],0);
		}
		pair<double,pair<int,int> > path[n+1];
		for(int i=1;i<=n;i++){
			path[i] = make_pair(1,make_pair(i,i));
		}
		int total=0;
		double ans=0;
		while(!mul.empty()){
			total++;
			pair<double,pair<int,int> > p = *mul.begin();
			mul.erase(mul.begin());
 
			int endpoint1 = p.second.first;
			int endpoint2 = p.second.second;
			double w = p.first;
			if(total == n){ans = max(ans,w);}
 
			double summax=w;
			int firstpoint,secondpoint;
			double totalpoints;
			for(int i=0;i<(int)G[endpoint1].size();i++){
				int v = G[endpoint1][i];
				if(val[v].second >= 2){continue;}
				else{
					int v1 = path[v].second.first;
					int v2 = path[v].second.second;
 
					if(v2==v){
						int temp=v1;
						v1 = v2;
						v2 = temp;
					}
					double temp = (w*path[endpoint1].first) + (val[v1].first * path[v1].first);
					temp = temp/(path[endpoint1].first + path[v1].first);
					if(summax < temp){
						summax = temp;
						firstpoint = v2;
						secondpoint = endpoint2;
						totalpoints = path[endpoint1].first + path[v1].first;
					}
				}
			}
 
			for(int i=0;i<(int)G[endpoint2].size();i++){
				int v = G[endpoint2][i];
				if(val[v].second >= 2){continue;}
				else{
					int v1 = path[v].second.first;
					int v2 = path[v].second.second;
 
					if(v2==v){
						int temp=v1;
						v1 = v2;
						v2 = temp;
					}
					double temp = (w*path[endpoint2].first) + (val[v1].first * path[v1].first);
					temp = temp/(path[endpoint2].first + path[v1].first);
					if(summax < temp){
						summax = temp;
						firstpoint = v2;
						secondpoint = endpoint1;
						totalpoints = path[endpoint2].first + path[v1].first;
					}
				}
			}
 
			if(summax==w ){ans = max(ans,summax);break;}
			else{
				int v1 = path[firstpoint].second.first;
				int v2 = path[firstpoint].second.second;
				if(v2==firstpoint){
					int temp=v1;
					v1 = v2;
					v2 = temp;
				}
				double we = val[firstpoint].first;
			//	cout<<"executed"<<endl;
				if(mul.find(make_pair(we,make_pair(v1,v2)))!=mul.end()){
					mul.erase(mul.find(make_pair(we,make_pair(v1,v2))));
				}else{
					mul.find(make_pair(we,make_pair(v2,v1)));
				}
				val[v1].first = summax;
				val[v2].first = summax;
				val[v2].second++;
				path[v1].first = totalpoints;
				path[v1].second.first = firstpoint;
				path[v1].second.second = secondpoint;
				path[v2].second.first = firstpoint;
				path[v2].second.second = secondpoint;
 
				v1 = path[secondpoint].second.first;
				v2 = path[secondpoint].second.second;
				if(v2==secondpoint){
					int temp=v1;
					v1 = v2;
					v2 = temp;
				}
				we = val[secondpoint].first;
				
				val[v1].first = summax;
				val[v2].first = summax;
				val[v2].second++;
				path[v1].first = totalpoints;
				path[v1].second.first = firstpoint;
				path[v1].second.second = secondpoint;
				path[v2].second.first = firstpoint;
				path[v2].second.second = secondpoint;
				mul.insert(make_pair(summax,make_pair(firstpoint,secondpoint)));
			}
		}
		printf("%.12lf\n",ans);
	}
}
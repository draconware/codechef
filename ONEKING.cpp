#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<pair<int,int> > v;
		for(int i=0,x,y;i<n;i++){
			cin>>x>>y;
			v.push_back(make_pair(y,x));
		}
		sort(v.begin(),v.end());
		int ans=0,val=-1;
		for(int i=0;i<n;){
			val=v[i++].first;ans++;
			while(i<n && val>=v[i].second)
		}
	}
}
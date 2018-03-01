#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<vector<LL> > G,prefix,suffix;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin>>k;

	for(int i=0;i<k;i++){
		int n;
		cin>>n;

		LL a,sum=0;
		vector<LL> v;
		for(int j=0;j<n;j++){
			cin>>a;
			v.push_back(a);
			sum+=a;
		}
		sort(v.begin(),v.end());
		G.push_back(v);
		vector<LL> prefixt,suffixt;
		prefixt.push_back(v[0]);
		for(int j=1;j<n;j++){prefixt.push_back(prefixt[j-1]+v[j]);}
		prefix.push_back(prefixt);

		suffixt.push_back(sum);
		for(int j=1;j<n;j++){
			suffixt.push_back(suffixt[j-1]-v[j-1]);
		}
		suffix.push_back(suffixt);
	}

	map<pair<int,int>,LL> mp;
	int q;
	cin>>q;

	while(q--){
		int l,r;
		cin>>l>>r;
		l--;r--;

		if(mp.find(make_pair(min(l,r),max(l,r)))!=mp.end()){
			cout<<mp[make_pair(min(l,r),max(l,r))]<<endl;
		}else{
			LL ans = 0;
			if(G[l].size() > G[r].size()){int t=l;l=r;r=t;}

			int n = (int)G[l].size();
			int len = (int)G[r].size();
			for(int i=0;i<n;i++){
				vector<LL>::iterator it = upper_bound(G[r].begin(),G[r].end(),G[l][i]);

				int j = it-G[r].begin();
				if(j==len){ans = ans + (G[l][i]*j) - (prefix[r][len-1]);}
				else{ans = ans + (G[l][i]*j) - (prefix[r][j]-G[r][j]) - (G[l][i]*(len-j)) + (suffix[r][j]);}
			}
			mp[make_pair(min(l,r),max(l,r))] = ans;
			cout<<ans<<endl;
		}
	}
}
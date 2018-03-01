#include<bits/stdc++.h>
using namespace std;

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

		string s;
		vector<string> prob;
		for(int i=0;i<m;i++){
			cin>>s;prob.push_back(s);
		}
		//for(int i=0;i<prob.size();i++){cout<<prob[i]<<" ";}cout<<endl;
		map<pair<string,string>,int> mm;
		set<string> part;
		string user;
		map<string,pair<int,int> > part_score;

		for(int i=0,x;i<n;i++){
			cin>>user>>s>>x;
			part.insert(user);
			if(mm[make_pair(user,s)]!=0){
				int y = mm[make_pair(user,s)];
				if(x>y){part_score[user].first += (x-y);part_score[user].second = m-i;}
			}else{
				mm[make_pair(user,s)]=x;
				part_score[user].first += x;
				part_score[user].second = m-i;
			}
		}

		int X = part.size();
		cout<<X<<endl;

		priority_queue<pair<pair<int,int>,string> > q;
		for(set<string>::iterator it=part.begin();it!=part.end();it++){
			q.push(make_pair(part_score[*it],*it));//cout<< *it <<" "; 
		}
		//cout<<endl;

		while(!q.empty()){
			cout<<q.top().second<<" "<<q.top().first.first<<endl;
			q.pop();
		}
	}
	return 0;
}
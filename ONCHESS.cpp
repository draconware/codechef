#include<bits/stdc++.h>
using namespace std;

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
		int n;
		cin>>n;

		bool mark[n];
		memset(mark,0,sizeof(mark));

		vector<pair<int,pair<pair<int,int>,pair<int,pair<string,string> > > > > v;
		int r,mini,maxi,timei;
		string rate,color;
		cin>>r>>mini>>maxi>>timei>>rate>>color;
		v.push_back(make_pair(r,make_pair(make_pair(mini,maxi),make_pair(timei,make_pair(rate,color)))));
		cout<<"wait"<<endl;
		for(int i=1;i<n;i++){
			cin>>r>>mini>>maxi>>timei>>rate>>color;
			v.push_back(make_pair(r,make_pair(make_pair(mini,maxi),make_pair(timei,make_pair(rate,color)))));
			bool flag=true;
			for(int j=0;j<i;j++){
				if(!mark[j]){
					int nr = v[j].first;
					int nmini = v[j].second.first.first;
					int nmaxi = v[j].second.first.second;
					int ntimei = v[j].second.second.first;
					string nrate = v[j].second.second.second.first;
					string ncolor = v[j].second.second.second.second;
					
					if(r>nmaxi || r<nmini){continue;}
					//if(i==6 && j==4){cout<<"executed"<<endl;}
					if(nr>maxi || nr<mini){continue;}
					//if(i==6 && j==4){cout<<"executed"<<endl;}
					if(timei != ntimei){continue;}
					//if(i==6 && j==4){cout<<"executed"<<endl;}
					if(rate != nrate){continue;}
					//if(i==6 && j==4){cout<<"executed"<<endl;}
					if(color=="white" && ncolor=="black"){

					}else if(ncolor=="white" && color=="black"){

					}else if(color=="random" && ncolor=="random"){

					}else{
						continue;
					}
					//if(i==6 && j==4){cout<<"executed"<<endl;}
					mark[j]=true;
					mark[i]=true;
					cout<<j+1<<endl;
					flag=false;
					break;
				}
			}
			if(flag){cout<<"wait"<<endl;}
		}
	}
}
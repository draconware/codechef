#include<bits/stdc++.h>
using namespace std;
 
map<string,int> mp;
map<string,bool> mark;
 
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
 
		string s;
		vector<string> v;
		for(int i=0;i<n;i++){
			cin>>s;
			mp[s]++;
			v.push_back(s);
		}
 
		int arr[2];
		vector<string> res;
		int k=0;
		for(int i=0;i<n;i++){
			if(!mark[v[i]]){
				mark[v[i]]=true;
				arr[k++]=mp[v[i]];
				res.push_back(v[i]);
			}
		}
		if(k==0){cout<<"Draw"<<endl;}
		else if(k==1){cout<<res[0]<<endl;}
		else{
			if(arr[0] == arr[1]){cout<<"Draw"<<endl;}
			else if(arr[0]>arr[1]){cout<<res[0]<<endl;}
			else{cout<<res[1]<<endl;}
		}
		for(int i=0;i<n;i++){
			mp[v[i]] = 0;
			mark[v[i]] = false;
		}
	}
} 
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
		map<string,bool> m;
		int n;
		cin>>n;

		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			m[s]=true;
		}
		if(m["cakewalk"] && m["simple"] && m["easy"] && (m["easy-medium"]||m["medium"]) && (m["medium-hard"] || m["hard"])){cout<<"Yes"<<endl;}
		else{cout<<"No"<<endl;}
	}
}
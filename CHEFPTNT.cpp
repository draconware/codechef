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
		int n,m,x,k;
		cin>>n>>m>>x>>k;

		string s;
		cin>>s;

		int even=0,odd=0;
		for(int i=0;i<k;i++){
			if(s[i]=='E'){even++;}
			else{odd++;}
		}

		for(int i=1;i<=m;i++){
			if(i%2){
				n -= min(x,odd);
				odd -= min(x,odd);
			}else{
				n -= min(x,even);
				even -= min(x,even);
			}
		}
		if(n>0){
			cout<<"no"<<endl;
		}else{
			cout<<"yes"<<endl;
		}
	}
}
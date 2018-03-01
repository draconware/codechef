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
		int n;
		long long arr[30];
		bool mark[30];
		memset(mark,0,sizeof(mark));
		for(int i=0;i<26;i++){
			cin>>arr[i];
		}
		string s;
		cin>>s;
		n=(int)s.length();
		for(int i=0;i<n;i++){
			mark[s[i]-'a']=true;
		}
		long long ans=0;
		for(int i=0;i<26;i++){
			if(!mark[i]){ans+=arr[i];}
		}
		cout<<ans<<endl;
	}
	return 0;
}
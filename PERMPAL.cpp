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
		string s;
		cin>>s;

		int arr[26];
		memset(arr,0,sizeof(arr));

		int n = (int)s.length();
		for(int i=0;i<n;i++){
			arr[s[i]-'a']++;
		}

		int odd=0;
		for(int i=0;i<26;i++){
			if(arr[i]%2 == 1){odd++;}
		}
		if(n&1){
			if(odd>1){cout<<"-1"<<endl;continue;}
		}else{
			if(odd>0){cout<<"-1"<<endl;continue;}
		}

		vector<int> G[30];
		for(int i=0;i<n;i++){
			G[s[i]-'a'].push_back(i);
		}
		int res[n];
		int a=0,b=n-1,idx;
		for(int i=0;i<26;i++){
			int len = (int)G[i].size();
			if(len>0){
				if(len%2 == 0){
					for(int j=0;j<len;j+=2){
						res[a] = G[i][j];
						res[b] = G[i][j+1];
						a++;b--;
					}
				}else{
					for(int j=0;j<len-1;j+=2){
						res[a] = G[i][j];
						res[b] = G[i][j+1];
						a++;b--;
					}
					idx = G[i][len-1];
				}
			}
		}
		if(n&1){res[a] = idx;}
		for(int i=0;i<n;i++){
			cout<<res[i]+1<<" ";
		}
		cout<<endl;
	}
}
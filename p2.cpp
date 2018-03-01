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

		string ans;
		int n = (int)s.length();

		for(int i=0;i<n;i++){
			int x;char y;
			if(s[i]>='a' && s[i]<='z'){x = s[i]-'a';x = (x+i+1)%26;y = 'A'+x;}
			else{x = s[i]-'A';x = (x+i+1)%26;y = 'a'+x;}
			ans.push_back(y);
		}
		cout<<ans<<endl;
	}
}
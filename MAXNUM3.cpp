#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		int n = (int)s.length();
		vector<int> v;
		for(int i=0;i<n;i++){v.push_back(s[i]-'0');}
		int total=0;
		for(int i=0;i<n;i++){
			total += v[i];
		}
		//cout<<total<<" ";
		string ans = "";
		for(int i=0;i<n;i++){
			int temp = total - v[i];
			if(i<n-1){
				if(v[n-1]%2==0 && temp%3==0){
					ans = max(ans,s.substr(0,i)+s.substr(i+1,n));
				}
			}else{
				if(v[n-2]%2==0 && temp%3==0){
					ans = max(ans,s.substr(0,n-1));
				}
			}
		}
		if(ans.length() > 0){cout<<ans<<endl;}
		else{cout<<"-1"<<endl;}
	}
}
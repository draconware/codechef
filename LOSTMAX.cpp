#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);

		vector<int> v,ans;
		int res=0;
		for(int i=0;i<s.length();i++){
			if(s[i] == ' '){
				v.push_back(res);
				res=0;
			}else{
				res = res*10+(s[i]-'0');
			}
		}
		if(res>0){v.push_back(res);}res=0;
		int n=v.size(),val;
		bool flag=false;
		for(int i=0;i<n;i++){
			if(v[i] == n-1){
				if(flag){ans.push_back(v[i]);}
				flag=true;
			}else{
				ans.push_back(v[i]);
			}
		}
		for(int i=0;i<ans.size();i++){
			res = max(res,ans[i]);
		}
		cout<<res<<endl;
	}
	return 0;
}
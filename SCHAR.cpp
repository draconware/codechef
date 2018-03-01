#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> v[30];
int val[100009];
int MAX = 10000000;
int n;

int dp(int idx){
	if(val[idx]!=-1){return val[idx];}
	
	if(idx+1 < n){
		int sum = abs(s[idx]-s[idx+1])+dp(idx+1);
		vector<int>::iterator it = upper_bound(v[s[idx]-'a'].begin(),v[s[idx]-'a'].end(),idx);
		
		for(;it!=v[s[idx]-'a'].end();it++){
			sum=min(sum,dp( *it));
		}
		val[idx]=sum;
		cout<<idx<<","<<val[idx]<<endl;
		return val[idx];
	}else{
		val[idx]=0;
		cout<<idx<<","<<val[idx]<<endl;
		return 0;
	}
}

int main(){
	int t;
	cin>>t;

	while(t--){
		memset(val,-1,sizeof(val));
		cin>>s;
		n = (int)s.length();
		for(int i=0;i<(int)s.length();i++){
			v[s[i]-'a'].push_back(i);
		}
		
		cout<<dp(0)<<endl;
	}
}
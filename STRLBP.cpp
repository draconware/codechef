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
		int n = (int)s.length();

		int x=0;
		for(int i=1;i<=n;i++){
			if(s[i%n]!=s[i-1]){x++;}
		}
		if(x>2){cout<<"non-uniform"<<endl;}
		else{cout<<"uniform"<<endl;}
	}
}
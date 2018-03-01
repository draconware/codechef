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
		string s;cin>>s;
		int arr[30];
		memset(arr,0,sizeof(arr));

		bool flag=false;
		for(int i=0;i<(int)s.length();i++){
			arr[s[i]-'a']++;
			if(arr[s[i]-'a']>1){flag=true;break;}
		}
		if(flag){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}
}
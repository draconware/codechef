#include<bits/stdc++.h>
using namespace std;

int main(){
  	#ifndef ONLINE_JUDGE
  	freopen("input.in","r",stdin);
  	freopen("output.out","w",stdout);
  	#endif

	int n,q;
	cin>>n>>q;

	int x,c=0,a=0,b=1,ans=0;
	int val[n+9];
	memset(val,0,sizeof(val));
	string s;
	while(q--){
		cin>>s;
		if(s == "CLICK"){
			cin>>x;val[x]++;
			if(val[x]%2 == 0){ans--;}
			else{ans++;}
			cout<<ans<<endl;
		}else{
			ans=0;
			memset(val,0,sizeof(val));
			cout<<ans<<endl;
		}
	}
}
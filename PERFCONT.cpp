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
		int n,p;
		cin>>n>>p;

		int x=0,y=0;
		for(int i=0;i<n;i++){
			int a;cin>>a;
			if(a >= (p/2)){x++;}
			if(a <= (p/10)){y++;}
		}
		if(x==1 && y==2){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}
	return 0;
}
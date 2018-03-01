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

		if(p<=2){cout<<"impossible"<<endl;}
		else{
			for(int i=1;i<=n;i+=p){
				cout<<"a";
				for(int j=1;j<=p-2;j++){
					cout<<"b";
				}
				cout<<"a";
			}
			cout<<endl;
		}
	}
}
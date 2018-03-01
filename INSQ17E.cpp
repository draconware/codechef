#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL M = 1e9+7;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		LL m;
		cin>>m;

		if(m<=3){cout<<"0"<<endl;}
		//cout<<(m%M)<<" ";
		LL a = m%M;
		a = (a*((m-1)%M))%M;
		a = (a*((m-2)%M))%M;
		a = (a*((m-3)%M))%M;
		a = (a*125000001)%M;
		cout<<a<<endl;
	}	
	return 0;
}

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

	int t;cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		if(n==1){cout<<"0"<<endl;}
		else{
			int x = (int)ceil(log2((float)n));
			int y = (int)pow(2,x);

			if(y-n <= 1){
				cout<<x*m<<endl;
			}else{
				cout<<x*m - (m-1)<<endl;
			}
		}
	}
}
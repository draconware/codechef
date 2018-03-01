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
		int n,s;
		cin>>n>>s;

		if(n==1 && s!=0){cout<<"-1"<<endl;}
		else{
			if(s==0){
				for(int i=0;i<n;i++){cout<<"0 ";}cout<<endl;
			}else if(n%2==0){
				int x = s;
				for(int i=1;i<=(n/2);i++){cout<<(-x)<<" ";}
				for(int i=(n/2)+1;i<=n;i++){cout<<x<<" ";}
				cout<<endl;
			}else if(n%2 == 1){
				float x = sqrt((float)n/(float)(n-1))*((float)s);
				cout.precision(7);
				for(int i=1;i<=(n/2);i++){cout<<(-x)<<" ";}
				cout<<"0"<<" ";
				for(int i=(n/2)+2;i<=n;i++){cout<<x<<" ";}
				cout<<endl;
			}
		}
	}
}
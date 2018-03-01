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
		int n;
		cin>>n;

		if(n%2 == 0){
			for(int i=1;i<=n;i+=2){
				cout<<i+1<<" "<<i<<" ";
			}
			cout<<endl;
		}else{
			for(int i=1;i<=n-3;i+=2){
				cout<<i+1<<" "<<i<<" ";
			}
			cout<<n-1<<" "<<n<<" "<<n-2<<endl;
		}
	}
	return 0;
}
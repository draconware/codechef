#include<bits/stdc++.h>
using namespace std;

#define LL long long

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
		int n;
		cin>>n;

		LL arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}

		int p,q;cin>>p>>q;
		p--;q--;

		cout<<abs(arr[p]-arr[q])<<endl;
	}
}
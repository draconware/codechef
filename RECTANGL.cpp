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
		int arr[4];
		for(int i=0;i<4;i++){cin>>arr[i];}

		sort(arr,arr+4);
		if((arr[0]==arr[1]) && (arr[2]==arr[3])){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}
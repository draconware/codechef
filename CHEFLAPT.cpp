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
		int n;
		cin>>n;

		int arr[n];
		int mark[109];
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){cin>>arr[i];mark[arr[i]]++;}
		sort(arr,arr+n);

		for(int i=0;i<n;i++){
			if(mark[arr[i]]==1){cout<<arr[i]<<endl;break;}
		}
	}
	return 0;
}
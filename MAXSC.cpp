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

		LL arr[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
			sort(arr[i],arr[i]+n);
		}

		bool flag=true;
		LL sum = arr[n-1][n-1];
		LL prev = arr[n-1][n-1];
		for(int i=n-2;i>=0;i--){
			LL x=-1;
			for(int j=0;j<n;j++){
				if(arr[i][j] >= prev){break;}
				x = arr[i][j];
			}
			if(x==-1){flag=false;break;}
			else{sum = sum + x;prev=x;}
		}
		if(!flag){cout<<"-1"<<endl;}
		else{cout<<sum<<endl;}
	}
}
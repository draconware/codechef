#include<bits/stdc++.h>
using namespace std;

int res[1009];
int arr[1009][1009];

void solve(int n){
	int idx=0;
	memset(res,0,sizeof(res));
	while(idx<n && arr[0][idx] == 0){idx++;}
	for(int i=idx;i<n;i++){
		if(i==idx){res[i] = -arr[0][i];}
		else if(arr[i][idx] == arr[0][i] + arr[0][idx]){res[i]=arr[0][i];}
		else{res[i] = -arr[0][i];}
	}
	for(int i=0;i<n;i++){cout<<res[i]<<" ";}
	cout<<endl;
}

int main(){
	int n,q;
	cin>>n>>q;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	solve(n);

	while(q--){
		int p;
		cin>>p;

		for(int i=0;i<n;i++){cin>>arr[p-1][i];arr[i][p-1]=arr[p-1][i];}
		solve(n);
	}
	return 0;
}
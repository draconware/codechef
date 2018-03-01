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
		int n;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}

		int even=0,odd=0;
		for(int i=0;i<n;i++){
			if(arr[i]&1){odd++;}
			else{even++;}
		}

		if(odd&1){
			if(odd==1){
				if(even>0){cout<<"2"<<endl;}
				else{cout<<"1"<<endl;}
			}else{
				cout<<"2"<<endl;
			}
		}else{
			cout<<"1"<<endl;
		}
	}
}
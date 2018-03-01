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
		int n,r;cin>>n>>r;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		int s=INT_MIN,e = INT_MAX;
		if(n==1){cout<<"YES"<<endl;}
		else{
			if(arr[0]>r){e=arr[0];}
			else{s=arr[0];}
			bool flag=true;
			for(int i=1;i<n;i++){
				if(arr[i]>s && arr[i]<e){
					if(arr[i]>r){e=min(arr[i],e);}
					else if(arr[i]<r){s = max(s,arr[i]);}
					else{break;}
				}else{
					flag=false;
				}
			}
			if(flag){cout<<"YES"<<endl;}
			else{cout<<"NO"<<endl;}
		}
	}
}
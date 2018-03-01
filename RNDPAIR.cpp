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

		int arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}

		int maxi=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				maxi = max(maxi,arr[i]+arr[j]);
			}
		}
		int x=0,y=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(arr[i]+arr[j] == maxi){x++;}
				y++;
			}
		}
		double ans = (double)x/(double)y;
		printf("%.13lf\n",ans);
	}
}
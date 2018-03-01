#include"bits/stdc++.h"
using namespace std;
#define LL long long
int main(){
	int t;
	cin>>t;

	while(t--){
		int n,d;
		LL sum=0;
		cin>>n>>d;

		vector<LL> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%n == 0){
			LL val=sum/n,moves=0;
			for(int i=0;i<n-d;i++){
				if(arr[i] != val){
					if(arr[i]>val){
						moves+=(arr[i]-val);
						arr[i+d]+=(arr[i]-val);
						arr[i]-=(arr[i]-val);
					}else{
						moves+=(val-arr[i]);
						arr[i+d]-=(val-arr[i]);
						arr[i]+=(val-arr[]);
					}
				}
			}
			bool flag=true;
			for(int i=0;i<n;i++){
				if(arr[i]!=val){flag=false;break;}
			}
			if(flag){cout<<moves<<endl;}
			else{cout<<"-1"<<endl;}
		}else{
			cout<<"-1"<<endl;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL val[1000009];

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		memset(val,-1,sizeof(val));
		//val[0] = (LL)((zeros*(zeros-1))/2);
		LL ans=0;
		for(int i=0;i<n;i++){
			if(val[i] != -1){}
		}
	}
}
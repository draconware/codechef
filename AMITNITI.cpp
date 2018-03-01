#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	LL arr[34];
	arr[0]=2;arr[1]=7;
	for(int i=2;i<34;i++){
		if(i%2 == 0){
			arr[i] = arr[i-1] + 3*arr[i-2];
		}else{
			v[i] = v[i-1] + 7;
		}
	}
	vector<LL> v1,v2;
	LL total = 1<<17;
	for(LL i=0;i<total;i++){
		LL sum=0;
		for(int j=0;j<17;j++){
			if(i&(1<<j)){
				sum+=arr[j];
			}
		}
		v1.push_back(sum);
	}
	LL total = 1<<16;
	for(LL i=0;i<total;i++){
		LL sum=0;
		for(int j=0;j<16;j++){
			if(i&(1<<j)){
				sum+=arr[j+17];
			}
		}
		v2.push_back(sum);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	v1.erase(0);
	int t;
	cin>>t;

	while(t--){
		LL n;
		cin>>n;

		if(binary_search(v1.begin(),v1.end(),n) || binary_search(v2.begin(),v2.end(),n)){
			cout<<"YES"<<endl;
		}else{
			bool flag=false;
			vector<LL>::iterator it = upper_bound(v1.begin(),v1.end(),n);
			int j=it-v1.begin();

			for(int i=0;i<j;i++){
				if(binary_search(v2.begin(),v2.end(),n-v1[i])){
					flag=true;break;
				}
			}
			if(flag){cout<<"YES"<<endl;}
			else{cout<<"NO"<<endl;}
		}
	}
}
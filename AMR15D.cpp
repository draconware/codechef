#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,n;
	cin>>n;

	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int sum[n];
	sum[0]=v[0];
	for(int i=1;i<n;i++){
		sum[i]+=sum[i-1];
	}
	int q;
	cin>>q;

	while(q--){
		cin>>x;
		int y = (int)ceil(n/(k+1));
		cout<<sum[y-1]<<endl;
	}
	return 0;
}
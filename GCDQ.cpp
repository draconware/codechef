#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
	while(x>0){
		int temp=x;
		x=y%x;
		y=temp;
	}
	return y;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,q;
		cin>>n>>q;

		vector<int> v,pre,suff(n);
		for(int i=0,x;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		pre.push_back(v[0]);
		for(int i=1;i<n;i++){
			pre.push_back(gcd(pre[i-1],v[i]));
		}
		//for(int i=0;i<n;i++){cout<<pre[i]<<" ";}cout<<endl;
		suff[n-1]=v[n-1];
		for(int i=n-2;i>=0;i--){
			suff[i]=gcd(suff[i+1],v[i]);
		}
		//for(int i=0;i<n;i++){cout<<suff[i]<<" ";}cout<<endl;
		while(q--){
			int l,r;
			cin>>l>>r;

			if(l-1>=1 && r+1<=n){
				cout<<gcd(pre[l-2],suff[r])<<endl;
			}else if(l-1>=1){
				cout<<pre[l-2]<<endl;
			}else if(r+1<=n){
				cout<<suff[r]<<endl;
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long

LL power(int m){
	LL res=1;
	for(int i=0;i<m;i++){
		res*=2;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int t;
	cin>>t;

	while(t--){
		int n;
		LL k;
		cin>>n>>k;
		cout<<n<<" "<<k<<endl;
		LL idx=k,i=power(n-1),j=power(n);
		cout<<idx<<" "<<i<<" "<<j<<endl;
		if(k==0 || k==j-1){cout<<k<<endl;continue;}
		while(k>0){
			//cout<<idx<<","<<k<<" ";
			if(k%2 == 1){
				idx = idx + (i - k/2 - 1);
				k--;
				k/=2;
				i/=2;
				j/=2;
			}else{
				idx = idx - (i - (j-k)/2);
				k/=2;
				i/=2;
				j/=2;
			}
		}
		//cout<<endl;
		cout<<idx<<endl;
	}
	return 0;
}
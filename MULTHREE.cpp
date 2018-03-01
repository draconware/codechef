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
		long long k,a,b;
		cin>>k>>a>>b;

		long long ans = a+b;
		long long x = (a+b)%10;
		//cout<<x<<" ";
		if(x==5){
			if(k>=3){ans = ans + x;}
			if(ans%3 == 0){cout<<"YES"<<endl;}
			else{cout<<"NO"<<endl;}
			continue;
		}else if(x==0){
			if(ans%3 == 0){cout<<"YES"<<endl;}
			else{cout<<"NO"<<endl;}
			continue;
		}

		long long s=2;
		while(x!=2 && s<k){
			s++;
			ans = (ans + x);
			x = (2*x)%10;
		}
		s = k - s;
		long long g = s/4;
		ans = ans + (g%3)*20 + (long long)pow(2.0,s%4 + 1);
		ans = ans - 2;
		if(ans%3 == 0){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL p = 1000000006;
LL mod = 1000000007;

LL power(LL a, LL b, LL mod){
	LL x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}	
 
LL modular_inverse(LL n, LL mod){
	return power(n, mod-2, mod);
}
 
LL nCr(LL n, LL k, LL mod){
	return (factorial[n]*((modular_inverse(factorial[k]*modular_inverse(factorial[n-k]))%mod))%mod;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		int  m = 0,x=n/2;

		LL ans = 0;
		int l = n-k;
		for(int i=0;i<n/2;i++){
			if(s[i]!=s[n-1-i]){m++;}
		}
		int h = m;

		if(n%2 == 0){
			for(int i=l;i<=h;i++){
				ans = ans + ((power(2,ncr((LL)m,(LL)i,p),mod))%mod 
			}
			cout<<ans<<endl;
		}else{
			for(int i)
		}
	}
}
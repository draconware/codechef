#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
 
LL fact[1000009];
LL M = (LL)(1e9 + 7);
 
LL power(LL x,LL y){
	LL res=1;
	while(y>0){
		if(y%2 == 1){res = (res*x)%M;}
		y/=2;
		x = (x*x)%M;
	}
	return res;
}
 
LL inv(LL a, LL m)
{
    LL m0 = m;
    LL y = 0LL, x = 1LL;
 
    if (m == 1)
      return 0LL;
 
    while (a > 1LL)
    {
        // q is quotient
        LL q = a / m;
        LL t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0LL)
       x = (x+m0)%m0;
 
    return x;
}
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	fact[0]=fact[1] = 1LL;
	for(int i=2;i<1000009;i++){
		fact[i] = (fact[i-1]*i)%M;
	}
 
	int t;
	cin>>t;
 
	while(t--){
		LL l,d,n;
		cin>>l>>d>>n;
 
		if(floor(log2((long double)n)) == ceil(log2((long double)n))){
			LL x=1;
			LL p = d;
			LL q = l;
		//	cout<<p<<" "<<q<<endl;

			while(x<n){
				p = (2*((p*p)%M))%M - (q*q)%M;
				p = (p+M)%M;
				q = (q*q)%M;
			//	cout<<p<<" "<<q<<endl;
				x*=2;
			}
			q = (q*inv(l,M))%M;
			LL ans = (p*inv(q,M))%M;
			cout<<ans<<endl;
			continue;
		}

		LL p = power(d,n);
		LL q = power(l,n-1);
		LL c = ((l*l)%M - (d*d)%M + M)%M;
		//cout<<p<<" "<<q<<endl;
 	
		for(LL i=2;i<=n;i+=2){
			LL x = power(d,n-i);
			LL y = fact[n];
			LL z = (fact[i]*fact[n-i])%M;
			y = y*inv(z,M);
			y = y%M;
			x = (x*y)%M;
			x = (x*(power(c,i/2)))%M;
			if((i/2)%2 == 0){
				p = p+x;
				if(p>=M){p = p%M;}
			}else{
				p = p-x;
				if(p<0){p = (p+M)%M;}
			}
		}
		//cout<<p<<" "<<q<<endl;
		LL ans = (p*inv(q,M))%M;
		cout<<ans<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;

long long int m=1000000007;
long long int power(long long int a ,long long int b,long long int MOD)
{
    if(b==0)
   	 return 1;
    long long int ans = power(a,b/2,MOD);
    ans = (ans*ans)%MOD;
    if(b%2==1)
   	 ans=(ans*a)%MOD;
    return ans;
}
 
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int a,n,x,y;
		scanf("%lld",&a);
		n=((((a%m)*((a-1)%m)%m))*((((a-2)%m)*((a-3)%m))%m))%m;
		x=power(8,m-2,m)%m;
		cout<<x<<" ";
		y=(n*x)%m;
	    printf("%lld\n",y);	
      		
	}
	return 0;
} 
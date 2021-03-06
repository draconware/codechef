   #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define MOD 1000000007

    ll fact[2100000];

    ll pw(ll a, ll b)
    {
    	if(b==0)
    		return 1;
    	ll temp = pw(a,b/2);
    	temp = (temp*temp)%MOD;
    	if(b%2 == 0)
    		return temp;
    	else
    		return (temp*a)%MOD;
    }

    ll inv_mod(ll a)
    {
    	return pw(a,MOD-2);
    }

    ll NCR(ll n, ll r)
    {
    	ll ans = fact[n];
    	ans = (ans*inv_mod(fact[r]))%MOD;
    	ans = (ans*inv_mod(fact[n-r]))%MOD;
    	return ans;
    }

    int main()
    {
    	fact[0] = 1;
    	for(int i = 1 ; i < 2100000; i++)
    		fact[i] = (fact[i-1]*i)%MOD;
    	int t;
    	long n;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%ld",&n);
    		if(n<13)
    		printf("0\n");
    		else
    		{
    			n=n-13;
    			ll ans=0;
    			while(n>=0)
    			{
    				ans=(ans%MOD+NCR((n/2)+5,5)%MOD)%MOD;
    				n=n-2;
    			}
    			printf("%lld\n",ans);
    		}
    	}
    }

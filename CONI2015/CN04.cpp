#include <cstring>
#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

int mod=1000000007;
void multiply(ll F[2][2], ll M[2][2])
{
    ll x =  F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ll y =  F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ll z =  F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ll w =  F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x%mod;
    F[0][1] = y%mod;
    F[1][0] = z%mod;
    F[1][1] = w%mod;
}

void power(ll F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{2,3},{1,0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}


ll fibo_matrix(ll n)
{
    ll F[2][2] = {{2,3},{1,0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return 5*F[0][0]+2*F[0][1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
 		ll n;
        cin>>n;
        if(n==1)
        	cout<<5<<endl;
        else if(n==0)
        	cout<<2<<endl;
        else
        cout<<fibo_matrix(n)%mod<<endl;
    }
    return 0;
}

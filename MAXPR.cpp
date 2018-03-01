 #include<bits/stdc++.h>
    using namespace std;
 
    ///***********SEXY & I KNOW IT******************///
    #define uli unsigned long long int
    ///***input******// for +ve int
    inline uli in() {
        uli p=0; register char ch=0;
        while(ch<'0' or ch>'9') {ch=getchar();}
        while(ch>='0' and ch<='9') {p=(p<<1)+(p<<3)+ch-'0'; ch=getchar();}
        return p;
    }
    ///***output*****// for +ve int
    #define pc(x) putchar(x)
    inline void dukya(uli n){
            uli N = n, rev, count_ = 0;
            rev = N;
            if (N == 0) { pc('0'); pc('\n'); return ;}
            while ((rev % 10) == 0) { count_++; rev /= 10;}
            rev = 0;
            while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
            while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
            while (count_--) pc('0');
            pc('\n');
        }
    ///
    #define li  long long int
    #define ld  double
    #define chal(n) for(li i=0;i<n; ++i)
    #define ot(n) cout<<n<<"\n"
    #define vi vector<li>
    #define ii pair<li, li>
    #define p_b(n) push_back(n)
    #define wl(n) while(n--)
    #define ict int test_case=in(); wl(test_case)
    #define INF 1000000000009
    #define mod 1000000007
    #define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
    ///****************************************//
li fun(li arr[], li n)
{
 
    li ans=n+1;
    li mxele=-INF, mnele=INF;
    chal(n)
    {
        mnele=min(arr[i], mnele);
        mxele=max(mxele, arr[i]);
    }
    li sum[105];
    for(li diff=(mnele-mxele); diff<=(mxele-mnele); ++diff)
    {
        memset(sum, 0, sizeof sum);
       chal(n)
       {
           li add=1;
           if((arr[i]-diff)>=1&&(arr[i]-diff)<=100)
            add=(add+sum[arr[i]-diff])%mod;
           ans=(ans+(add-1+mod)%mod)%mod;
           sum[arr[i]]=(sum[arr[i]]+add)%mod;
       }
    }
    li cal=1;
    chal(n)
    {
        cal=(cal*2)%mod;
    }
    
    return (cal-ans+mod)%mod;
}
 
int main(){
ict
{
 
    li n=in();
    li arr[n];
    chal(n)
    arr[i]=in();
    ot(fun(arr, n));
 
}
 
	return 0;
}
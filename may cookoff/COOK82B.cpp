#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define MAX 100009
#define LL long long

vector<LL> prime;
bool mark[MAX];

void pre(){
    for(LL i=0;i<MAX;i++){
        mark[i]=true;
    }
    for(LL i=2;(i*i)<MAX;i++){
        if(mark[i]){
            for(LL j=(i*i);j<MAX;j+=i){
                mark[j]=false;
            }
        }
    }
    for(LL i=2;i<MAX;i++){
        if(mark[i]){
            prime.push_back(i);
            //cout<<i<<endl;
        }
    }
}

long long power(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res = (res*x)%M;
        }
        y/=2;
        x = (x*x)%M;
    }
    return res;
}

int main(){
    pre();

    map<LL,LL> primefactors;
    map<LL,LL>::iterator it;
    LL n,x;
    cin>>n;

    for(LL i=0;i<n;i++){
        cin>>x;
        for(LL j=0;j<prime.size();j++){
            while(x%prime[j] == 0){
                x/=prime[j];
                primefactors[ prime[j] ]++;
            }
        }
        if(x>1){
            primefactors[x]++;
        }
    }
    bool justdoit=true;
    long long ans=1;
    for(it=primefactors.begin();it!=primefactors.end();it++){
        if( (it->second)%n ){
            justdoit=false;
        }
        //cout<<it->first<<it->second<<endl;
        ans = (ans*power(it->first,(n+1 - (it->second)%(n+1))%(n+1)))%M;
    }
    if(justdoit){
        cout<<"justdoit"<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}

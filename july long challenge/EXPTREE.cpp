#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define M1 1000000009
#define M2 1000000007

int main(){
    int t;
    cin>>t;

    while(t--){
        LL n;
        cin>>n;

        if(n<=3){cout<<min(n-1,1)<<" "<<min(n,1)<<endl;}
        else{
            pair<LL,LL> p1,p2;
            p1.first=1;p1.second=1;p2.first=1;p2.second=1;
            for(LL i=2;i<=2*n-4;i++){
                (p1.first)*=i;
                (p1.first)%=M1;
                (p1.second)*=i;
                (p1.second)%=M2;
            }
            for(LL i=2;i<=(n-2);i++){
                (p2.first)*=i;
                (p2.first)%=M1;
                (p2.second)*=i;
                (p2.second)%=M2;
            }

        }
    }
}

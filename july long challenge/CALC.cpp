#include<bits/stdc++.h>
using namespace std;

#define ULL unsigned long long
ULL n,b;

ULL f(ULL x){
    return x*(n-(b*x));
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n>>b;

        if(b>=n){
            cout<<"0"<<endl;
        }else{
            ULL x = n/(2*b);
            if(x>0){
                cout<<max(f(x),max(f(x-1),f(x+1)))<<endl;
            }else{
                cout<<max(f(x),f(x+1))<<endl;
            }
        }
    }
    return 0;
}

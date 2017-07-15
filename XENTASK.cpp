#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    while(t--){
        LL n;
        cin>>n;

        LL x[n],y[n];
        for(LL i=0;i<n;i++){
            cin>>x[i];
        }
        for(LL i=0;i<n;i++){
            cin>>y[i];
        }
        LL ans1=0,ans2=0;

        for(LL i=0;i<n;i++){
            if(i%2){
                ans1+=y[i];
            }else{
                ans1+=x[i];
            }
        }

        for(LL i=0;i<n;i++){
            if(i%2){
                ans2+=x[i];
            }else{
                ans2+=y[i];
            }
        }
        LL ans=min(ans1,ans2);
        cout<<ans<<endl;
    }
    return 0;
}

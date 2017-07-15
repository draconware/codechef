#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    LL u,v;
    while(t--){
        cin>>u>>v;
        LL ans;
        if(u == 0){
            ans = 1+(v*(v+1))/2;
        }else if(v == 0){
            u++;
            ans = (u*(u+1))/2;
        }else{
            u++;
            ans = (u*(u+1))/2;
            ans += (u*v + v*(v-1)/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}

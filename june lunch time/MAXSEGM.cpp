#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<LL> v,sum;
set<LL> s;

int main(){
    int t;
    cin>>t;

    while(t--){
        v.clear();sum.clear();s.clear();
        sum.push_back(0);

        LL n,a;
        cin>>n;

        for(LL i=1;i<=n;i++){
            cin>>a;
            v.push_back(a);
        }
        for(LL i=1;i<=n;i++){
            cin>>a;
            sum.push_back(sum[i-1]+a);
        }
        LL l=1,r=1,ans=0;
        while(l<=r && l<=n && r<=n){
            if(l==r){
                ans = max(ans,sum[r]-sum[l-1]);
                r++;s.insert(v[r-1]);
            }else{
                s.insert(v[r-1]);
                if(s.size() == (r-l+1)){
                    ans = max(sum[r]-sum[l-1],ans);
                    r++;
                }else{
                    s.erase(v[l-1]);l++;
                }
            }
            cout<<l<<","<<r<<" "<<ans<<endl;
            set<LL>::iterator it;
            for(it = s.begin();it!=s.end();it++){cout<< *it <<" ";}
            cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

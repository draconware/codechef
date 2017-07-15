#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<bool> v;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,i,count=0;
        LL amount=0;
        bool p;
        cin>>n;

        for(i=0;i<n;i++){
            cin>>p;
            v.push_back(p);
        }

        for(i=0;i<n;i++){
            if(v[i]){
                continue;
            }
            break;
        }
        amount+=((n-i)*1100);

        for(int j=i;j<n;j++){
            if(v[j]){
                amount-=1000;
            }
        }
        cout<<amount<<endl;
        v.clear();
    }
    return 0;
}

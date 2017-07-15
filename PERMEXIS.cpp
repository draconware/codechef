#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i=0;i<n;i++){cin>>v[i];}
        sort(v.begin(),v.end());

        if(n==1){cout<<"YES"<<endl;}
        else{
            bool flag=true;
            for(int i=1;i<n;i++){
                if(abs(v[i]-v[i-1])>1){flag=false;}
            }
            if(flag){cout<<"YES"<<endl;}
            else{cout<<"NO"<<endl;}
        }
    }
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,p;
    cin>>t;

    vector<int> v;
    while(t--){
        cin>>n;

        int m=2*n;
        for(int i=0;i<m;i++){
            cin>>p;
            v.push_back(p);
        }
        sort(v.begin(),v.end());

        cout<< v[n-1+(n+1)/2] <<endl;

        for(int i=0,j=m-2;j>=n;j--,i+=2){
            swap(v[i],v[j]);
        }

        for(int i=0;i<m;i++){
            cout<<v[i]<<" ";
        }cout<<endl;
        v.clear();
    }
    return 0;
}

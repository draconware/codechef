#include<bits/stdc++.h>
using namespace std;

bool f(vector<int> &v,int n,int c,int m){
    int i=0;
    while(i<n-c+1){
        int k=c,j=i;
        while(j<n){
            k--;
            vector<int>::iterator it = lower_bound(v.begin(),v.end(),m+v[j]);
            if(it == v.end()){break;}
            else{
                j=it-v.begin();
            }
        }
        if(k == 0){return true;}
        i++;
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
    int n,c,a;
    cin>>n>>c;
    if(c>n){cout<<"0"<<endl;return 0;}
    vector<int> v;
    for(int i=0;i<n;i++){cin>>a;v.push_back(a);}
    sort(v.begin(),v.end());

    int l=1,h=(v[n-1]-v[0]);a=0;
    while(l<=h){
        int m = (l+h)/2;
        if(f(v,n,c,m)){
            a=m;
            l=m+1;
        }else{
            h=m-1;
        }
    }
    cout<<a<<endl;
    }
}

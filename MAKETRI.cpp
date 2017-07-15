#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    LL n,l,r,min1,max1,x;
    cin>>n>>l>>r;

    vector<pair<LL,LL> > v;
    pair<LL,LL> temp;

    LL arr[n],amount=0;
    int flag=1;

    for(LL i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for(LL i=0;i<n-1;i++){
        temp.first = arr[i+1] - arr[i]+1;
        temp.second = arr[i+1] + arr[i] -1;

        cout<<"element no. "<< i << " hold pair "<<temp.first<<","<<temp.second<<"."<<endl;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    min1=v[0].first; max1=v[0].second;

    if((min1 == l)&&(max1 == r)){
        amount+=(r-l+1);
        cout<<amount<<endl;
        return 0;
    }
    if(min1<l){
        min1=l;
    }
    if(max1>r){
        max1=r;
    }
    amount+=(max1-min1+1);
    for(LL i=1;i<v.size();i++){
        if(v[i].first)
    }
}

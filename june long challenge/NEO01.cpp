#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int n,t;
    cin>>t;

    while(t--){
        cin>>n;
        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> v;
        LL pos=0,neg=0,ans=0,j=0,temp=0,sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                neg+=arr[i];
                v.push_back(arr[i]);
            }else{
                pos+=arr[i];
                j++;
            }
        }
        ans = neg+(pos*j);
        //cout<<"first ans--- "<<ans<<endl;
        sort(v.begin(),v.end());
        int k=0;
        for(int i=v.size()-1;i>=0;i--,k++){
            temp+=v[i];
            //cout<<temp<<" "<<((j+k)*temp + (k+1)*pos)<<endl;
            sum = max(sum,((j+k)*temp + (k+1)*pos));
            //cout<<"posiible sum--- "<<sum<<endl;
        }
        if(sum>0){
            ans+=sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}

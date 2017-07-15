#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL n;
        cin>>n;

        LL arr[n];
        for(LL i=0;i<n;i++){
            cin>>arr[i];
        }

        if(n==1){
            cout<<arr[0]<<endl;
        }else{
            for(LL i=1;i<n;i+=2){
                LL temp=arr[i];
                arr[i]=max(arr[i],arr[i-1]);
                arr[i-1]=min(arr[i-1],temp);

                if(i < n-1){
                    temp=arr[i];
                    arr[i]=max(arr[i],arr[i+1]);
                    arr[i+1]=min(arr[i+1],temp);
                }
            }
        }
        for(LL i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

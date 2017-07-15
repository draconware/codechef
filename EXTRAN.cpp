#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n],flag=1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);

        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                flag=0;
                cout<<arr[i]<<endl;
                break;
            }
        }
        if(flag){
            if((arr[1]-arr[0])>1){
                cout<<arr[0]<<endl;
            }else if((arr[1]-arr[0])==0){
                cout<<arr[0]<<endl;
            }else if((arr[n-1]-arr[n-2])>1){
                cout<<arr[n-1]<<endl;
            }else if((arr[n-1]-arr[n-2])==0){
                cout<<arr[n-1]<<endl;
            }
        }
    }
    return 0;
}

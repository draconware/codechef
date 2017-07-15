#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

long long power(long long x,long long y){
    long long res=1;
    while(y>0){
        if(y&1){res*=x;res%=M;}
        y/=2;
        x = (x*x)%M;
    }
    return res;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n==1){cout<<"26"<<endl;}
        else{
            int arr[n];bool mark[n+1];
            long long ans=0;
            memset(mark,0,sizeof(mark));
            int j=0;
            for(int i=2;i<=n;i+=2){
                arr[j++]=i;
            }
            for(int i=1;i<=n;i+=2){
                arr[j++]=i;
            }
            //cout<<j<<endl;
            //for(int i=0;i<j;i++){cout<<arr[i]<<" ";}
            for(int i=1;i<=n;i++){
                if(!mark[i]){
                    mark[i]=true;
                    j=arr[i-1];
                    while(j != i){
                        mark[j]=true;
                        j=arr[j-1];
                    }
                    ans++;
                }
            }
            cout<<power(26,ans)%M<<endl;
        }
    }
}


#include<bits/stdc++.h>
using namespace std;

double arr[1009][1009];

int main(){
    for(int i=0;i<1009;i++){
        for(int j=0;j<=i;j++){
            if((j==0)||(j==i)){
                arr[i][j]=1.000000;
            }else{
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            }
        }
    }

    int t,s,m,n,k;
    cin>>t;

    while(t--){
        cin>>s>>n>>m>>k;
        double ans3,ans1,ans2,ans=0.000000;

        if(n==s){
            cout<<"1.000000"<<endl;
            continue;
        }
        if(n<=k){
            cout<<"0.000000"<<endl;
            continue;
        }
        for(int i=k;i<min(m,n);i++){
            ans1=arr[m-1][i];
            ans2=arr[s-m][n-1-i];

            ans=ans+(ans1*ans2);
            //cout<<"ans1 is --> "<<ans1<<" ans2 is --> "<<ans2<<" ans is --> "<<ans<<endl;
        }
        ans3=arr[s-1][n-1];
        ans=ans/ans3;

        printf("%0.6lf\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,p;
    cin>>n>>k>>p;

    vector<int> v(2*n),sum(2*n);
    for(int i=0;i<2*n;i++){sum[i]=0;}

    for(int i=0;i<n;i++){
        cin>>v[i];
        v[n+i]=v[i];
    }
    sum[0] = v[0];
    for(int i=1;i<k;i++){
        sum[i] = sum[i-1] + v[i];
    }
    for(int i=k;i<2*n;i++){
        sum[i] = sum[i-1] + v[i] - v[i-k];
    }

    int pos=n;
    char c;
    while(p--){
        cin>>c;
        if(c == '!'){
            pos--;
            if(pos == 0){
                pos = n;
            }
        }else{
            int ans = 0;
            int temp=k,j=n+pos-1;
            while(temp--){
                ans = max(ans,sum[j]);
                j--;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

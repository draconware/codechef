#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,m;
        cin>>n>>m;

        string s;
        cin>>s;

        int arr[n];
        for(int i=0;i<n;i++){
            arr[i] = s[i]-'0';
            //cout<<arr[i]<<endl;
        }
        int res[10][n];
        for(int i=0;i<10;i++){
            if(arr[0]==i){res[i][0]=1;}
            else{res[i][0]=0;}
            for(int j=1;j<n;j++){
                res[i][j]=res[i][j-1];
                if(arr[j]==i){res[i][j]++;}
            }
        }
        while(m--){
            int x,ans=0;
            cin>>x;
            x--;
            int y=arr[x];
            for(int i=0;i<y;i++){
                ans += (y-i)*(res[i][x]);
            }
            for(int i=y+1;i<10;i++){
                ans += (i-y)*(res[i][x]);
            }
            cout<<ans<<endl;

        }
}

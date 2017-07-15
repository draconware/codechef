#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long ans=0;
        int n,k,x,y;
        cin>>n>>k;

        vector<vector<bool> > v;
        vector<int> len;
        for(int i=0;i<n;i++){
            cin>>y;len.push_back(y);
            vector<bool> row(k+1,false);
            while(y--){
                cin>>x;
                row[x-1]=true;
            }
            v.push_back(row);
        }
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                flag=true;
                if(len[i]+len[j] >= k){
                    for(int c=0;c<k;c++){
                        if(!v[i][c] && !v[j][c]){flag=false;break;}
                    }
                }
                if(flag){ans++;}
            }
        }
        cout<<ans<<endl;
    }
}

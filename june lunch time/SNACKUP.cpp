#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int t;
    cin>>t;

    while(t--){
        v.clear();
        int n;
        cin>>n;

        cout<<n<<endl;
        for(int i=1;i<=n;i++){v.push_back(i);}
        for(int i=1;i<=n;i++){v.push_back(i);}
        int k=0;
        for(int i=1;i<=n;i++){
            int m=k;
            cout<<n<<endl;
            for(int j=1;j<=n;j++){
                cout<<j<<" "<<v[m]<<" "<<v[m+1]<<endl;
                m++;
            }
            k++;
        }
    }
    return 0;
}

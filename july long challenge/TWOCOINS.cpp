#include<bits/stdc++.h>
using namespace std;

#define MAX 100009

vector<int> v[MAX],rv[MAX];
vector<int> use;
bool mark[MAX];
bool coin[MAX];

int main(){
    int t;
    cin>>t;

    while(t--){
        for(int i=0;i<MAX;i++){v[i].clear();rv[i].clear();}
        use.clear();
        int n,x,y;
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            v[min(x,y)].push_back(max(x,y));
            rv[max(x,y)].push_back(min(x,y));
        }
        coin[1]=true;
        for(int i=1;i<=n;i++){
            if(v[i].size() == 0){
                use.push_back(i);
            }
        }

    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define MAX 3009

vector<int> v[MAX];
int disc[MAX];
int low[MAX];
bool mark[MAX];
int parent[MAX];
bool res[MAX];
int c;

void dfs(int s){
    mark[s]=true;
    disc[s]=c;
    low[s]=c;
    c++;
    int child=0;

    for(int i=0;i<v[s].size();i++){
        int u = v[s][i];
        if(parent[s] == u){
            continue;
        }
        if(!mark[u]){
            child++;
            parent[u]=s;
            dfs(u);

            low[s] = min(low[u],low[s]);
            if(low[u] >= disc[s] && parent[s] != -1){
                //cout<<s<<endl;
                res[s]=true;
            }
        }else{
            low[s] = min(low[s],disc[u]);
        }
    }
    if(child >= 2 && parent[s] == -1 ){
        res[s]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        c=0;
        int x,y,n,m,k;
        cin>>n>>m>>k;

        for(int i=0;i<n;i++){
            v[i].clear();
            mark[i]=false;
            res[i]=false;
            parent[i]=-1;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        dfs(0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(res[i]){ans++;}
        }
        cout<<ans*k<<endl;
    }
    return 0;
}

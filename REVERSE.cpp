#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,n,m;
    cin>>n>>m;

    vector< pair<int,int> > v[n+9];
    bool mark[n+9];
    int level[n+9];
    memset(mark,0,sizeof(mark));
    for(int i=0;i<=n;i++){level[i]=INT_MAX;}
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(make_pair(0,y));
        v[y].push_back(make_pair(1,x));
    }
    multiset<pair<int,int> > mul;
    mul.insert(make_pair(0,1));
    level[1]=0;

    while(!mul.empty()){
        pair<int,int> p = *mul.begin();
        mul.erase(mul.begin());

        int x=p.second;
        //cout<<x<<endl;
        if(mark[x]){continue;}
        mark[x]=true;

        for(int i=0;i<v[x].size();i++){
            int y=v[x][i].second,w=v[x][i].first;
            if(level[y] > level[x]+w){
                level[y]=level[x]+w;
                mul.insert(make_pair(level[y],y));
            }
        }
    }
    if(!mark[n]){
        cout<<"-1"<<endl;
    }else{
        cout<<level[n]<<endl;
    }
}

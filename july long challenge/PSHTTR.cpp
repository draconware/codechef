#include<bits/stdc++.h>
using namespace std;

#define MAX 100009

vector< pair<int,int> > v[MAX];
bool mark[MAX];
int ans;
bool flag;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        for(int i=0;i<MAX;i++){v[i].clear();}
        int n,x,y,z;
        scanf("%d", &n);

        for(int i=0;i<n-1;i++){
            scanf("%d", &x);scanf("%d", &y);scanf("%d", &z);
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
        }
        int m;
        scanf("%d", &m);

        while(m--){
            int a,b,c;
            scanf("%d", &a);scanf("%d", &b);scanf("%d", &c);
            flag=true;
            memset(mark,0,sizeof(mark));
            queue< pair<int,int> > q;
            q.push(make_pair(a,0));

            while(!q.empty()){
                pair<int,int> p = q.front();q.pop();
                x=p.first;int w=p.second;
                mark[x]=true;
                if(x == b){ans=w;break;}

                for(int i=0;i<v[x].size();i++){
                    y=v[x][i].first;z=v[x][i].second;
                    if(mark[y]){continue;}
                    if(z<=c){q.push(make_pair(y,z^w));}
                    else{q.push(make_pair(y,w));}
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

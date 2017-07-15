#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 100009

vector< pair<LL,pair<LL,LL> > > v[MAX];

int main(){
    int t;
    cin>>t;

    while(t--){
        LL n,d,x,y,z,w;
        cin>>n>>d;

        for(LL i=0;i<MAX;i++){v[i].clear();}
        for(LL i=0;i<n;i++){
            cin>>x>>y>>z;
            v[x].push_back(make_pair(z,make_pair(y,x)));
        }

        priority_queue< pair<pair<LL,LL> ,pair<LL,LL> > > q;

        for(LL i=1;i<=d;i++){
            for(LL j=0;j<v[i].size();j++){
                z=v[i][j].first;y=v[i][j].second.first;x=v[i][j].second.second;
                q.push(make_pair(make_pair(z,y),make_pair(x,j)));
            }
            if(q.empty()){continue;}
            pair<pair<LL,LL> ,pair<LL,LL> > p = q.top();q.pop();
            z=p.first.first;y=p.first.second;x=p.second.first;w=p.second.second;
            //cout<<x<<","<<y<<","<<z<<" updated to ";
            y--;
            if(y>0){
                q.push(make_pair(make_pair(z,y),make_pair(x,w)));
            }
            v[x][w].second.first = y;
            //cout<<x<<","<<y<<","<<z<<endl;
        }
        LL ans=0;
        for(LL i=1;i<=d;i++){
            for(LL j=0;j<v[i].size();j++){
                z=v[i][j].first;y=v[i][j].second.first;x=v[i][j].second.second;
                if(y > 0){
                    ans += (z*y);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

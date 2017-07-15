#include<bits/stdc++.h>
using namespace std;

#define MAX 50009
vector<int> v[MAX];

int main(){
    int t;
    cin>>t;

    while(t--){
        for(int i=0;i<MAX;i++){v[i].clear();}
        int n,x,y;
        cin>>n;

        vector<int> arr;
        set< pair<int,int> > s;
        set< pair<int,int> >::iterator it,temp=s.begin();
        for(int i=1;i<=n;i++){cin>>x;s.insert(make_pair(x,i));arr.push_back(x);}
        //pair<int,int> p = *it;
        //cout<<p.first <<","<<p.second<<endl;
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i=1;i<=n;i++){
            s.erase(make_pair(arr[i-1],i));
            s.insert(make_pair(0,i));
            for(int j=0;j<v[i].size();j++){
                s.erase(make_pair(arr[v[i][j]-1],v[i][j]));
                s.insert(make_pair(0,v[i][j]));
            }
            set<pair<int,int> >::reverse_iterator okay = s.rbegin();
            pair<int,int> p1 = *okay;
            if(p1.first == 0){cout<<"0"<<" ";}
            else{cout<<p1.second<<" ";}
            s.erase(make_pair(0,i));
            s.insert(make_pair(arr[i-1],i));
            for(int j=0;j<v[i].size();j++){
                s.erase(make_pair(0,v[i][j]));
                s.insert(make_pair(arr[v[i][j]-1],v[i][j]));
            }
        }
        cout<<endl;
    }
    return 0;
}

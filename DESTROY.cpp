#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
priority_queue<int> q;
vector<int> v;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,a;
        cin>>n;
        v.clear();m.clear();
        while(!q.empty()){q.pop();}
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
            m[a]++;
        }

        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            q.push(it->second);
        }
        int ans=0;
        while(q.top()>0){
            int a = q.top();q.pop();
            if(!q.empty() && q.top()>0){
                int b = q.top();q.pop();
                q.push(b-1);
                q.push(a-1);
            }else{
                q.push(a-1);
            }
            ans++;
        }
        cout<<ans<<endl;
    }
}

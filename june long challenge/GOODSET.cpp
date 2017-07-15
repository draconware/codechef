#include<bits/stdc++.h>
using namespace std;

#define LL long long

set<int> s;

void pre(){
    s.insert(1);
    set<int>::iterator it;
    for(int i=2;i<=500;i++){
        int flag=0;
        for(it=s.begin();it!=s.end();it++){
            int x = i-(*it);
            if(x == *it){
                flag=1;
            }else if(s.find(x) == s.end()){
                flag=1;
            }else{
                flag=0;
                break;
            }
        }
        if(flag){
            s.insert(i);
        }
    }
}

int main(){
    pre();
    int n,t;
    cin>>t;

    while(t--){
        cin>>n;

        set<int>::iterator it=s.begin();
        while(n--){
            cout<< *it <<" ";
            it++;
        }
        cout<<endl;
    }
    return 0;
}

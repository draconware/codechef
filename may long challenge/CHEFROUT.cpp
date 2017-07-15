#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    string s;
    while(t--){
        cin>>s;

        if(s.find("EC")<s.length()){
            cout<<"no"<<endl;
        }else if(s.find("SE")<s.length()){
            cout<<"no"<<endl;
        }else if(s.find("SC")<s.length()){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }
    }
    return 0;
}

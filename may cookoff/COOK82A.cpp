#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    string s;
    int x,a,b,c,d;
    while(t--){
        int n=4;
        while(n--){
            cin>>s;
            if(s == "Barcelona"){
                cin>>x;
                a=x;
            }else if(s == "Malaga"){
                cin>>x;
                b=x;
            }else if(s == "RealMadrid"){
                cin>>x;
                c=x;
            }else{
                cin>>x;
                d=x;
            }
        }
        if(c>=d){
            cout<<"RealMadrid"<<endl;
        }else{
            if(a>b){
                cout<<"Barcelona"<<endl;
            }
        }
    }
}

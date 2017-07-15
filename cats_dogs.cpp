#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    while(t--){
        int c,d,l,tempc;
        cin>>c>>d>>l;
        tempc=c;

        if(l%4){
            cout<<"no"<<endl;
        }else{
            l/=4;
            if(l<d){
                cout<<"no"<<endl;
            }else{
                if(c >= 2*d){
                    tempc-=2*d;
                }else{
                    tempc=0;
                }
                if((l>=(tempc+d))&&(l<=(c+d))){
                    cout<<"yes"<<endl;
                }else{
                    cout<<"no"<<endl;
                }
            }
        }
    }
    return 0;
}

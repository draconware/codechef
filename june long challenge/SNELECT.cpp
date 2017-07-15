#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    string s;
    while(t--){
        cin>>s;

        int snakes=0,mongoose=0,n=s.length();
        for(int i=0;i<n;i++){
            if(s[i] == 's'){
                snakes++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i] == 'm'){
                mongoose++;
            }
        }
        if(mongoose > snakes){
            cout<<"mongooses"<<endl;
        }else{
            for(int i=0;i<n;){
                if(s[i] == 's'){
                    if(s[i+1] == 'm'){
                        snakes--;
                        i+=2;
                    }else{
                        i++;
                    }
                }else{
                    if(s[i+1] == 's'){
                        snakes--;
                        i+=2;
                    }else{
                        i++;
                    }
                }
            }
            if(snakes > mongoose){
                cout<<"snakes"<<endl;
            }else if(snakes == mongoose){
                cout<<"tie"<<endl;
            }else{
                cout<<"mongooses"<<endl;
            }
        }
    }
    return 0;
}

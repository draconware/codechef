#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    string s;
    while(t--){
        cin>>s;
        int ans1=0,ans2=0,temp=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='U'){
                temp++;
            }else{
                if(temp>0){
                    ans1++;
                    temp=0;
                }
            }
        }
        if(temp>0){ans1++;}
        temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='D'){
                temp++;
            }else{
                if(temp>0){
                    ans2++;
                    temp=0;
                }
            }
        }
        if(temp>0){ans2++;}
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}

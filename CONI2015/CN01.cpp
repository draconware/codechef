#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin>>n;m=n;

    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='W'){
            n*=2;n+=11;
        }else{
            if(n%2==1){n++;}
            n/=2;
        }
    }
    cout<<n<<endl;
}

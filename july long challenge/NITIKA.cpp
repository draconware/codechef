#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    getchar();

    while(t--){
        string s,temp,res;
        getline(cin,s);
        //cout<<s.length()<<endl;
        bool flag=true;int x=0;
        vector<int> v;
        for(int i=0,j=0;i<s.length();i++){
            if(s[i] == ' '){flag=true;temp.push_back(s[i]);v.push_back(i);continue;}
            if(flag){
                temp.push_back(toupper(s[i]));
            }else{
                temp.push_back(tolower(s[i]));
            }
            flag=false;
        }
        int y=0,m=v.size();
        //cout<<m<<endl;
        while(m > x){
            res.push_back(temp[y]);
            res.push_back('.');
            res.push_back(' ');
            y=v[x];
            x++;y++;
        }
        for(int i=y;i<temp.length();i++){
            res.push_back(temp[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}

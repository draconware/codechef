#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int x=0,y=0,final_x=0,final_y=0,flag_x=0,flag_y=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '>'){
                if(flag_x == 1){
                    x++;
                    final_x = max(final_x,x);
                }else{
                    final_x = max(final_x,x);
                    x=1;
                    final_x = max(final_x,x);
                    flag_x=1;
                }
                flag_y=0;
            }else if(s[i] == '<'){
                if(flag_y == 1){
                    y++;
                    final_y = max(final_y,y);
                }else{
                    final_y = max(final_y,y);
                    y=1;
                    final_y = max(final_y,y);
                    flag_y=1;
                }
                flag_x=0;
            }
        }
        cout<< max(final_x,final_y)+1 <<endl;
    }
}

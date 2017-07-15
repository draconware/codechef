#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        char arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 'B'){
                    if(i+1<n && (arr[i+1][j]=='A' || arr[i+1][j]=='W')){
                        //cout<<"executed1"<<endl;
                        flag=false;break;
                    }
                }else if(arr[i][j] == 'A'){
                    if(i-1>=0 && arr[i-1][j]=='W'){
                        //cout<<"executed2"<<endl;
                        flag=false;break;
                    }
                    if(j-1>=0 && arr[i][j-1]=='W'){
                        //cout<<"executed2"<<endl;
                        flag=false;break;
                    }
                    if(j+1<m && arr[i][j+1]=='W'){
                        //cout<<"executed2"<<endl;
                        flag=false;break;
                    }
                }else{
                    if(j==0 || j==m-1 || i==n-1){
                        //cout<<"executed3"<<endl;
                        flag=false;break;
                    }
                }
            }
            if(!flag){break;}
        }
        if(!flag){cout<<"no"<<endl;}
        else{cout<<"yes"<<endl;}
    }
    return 0;
}

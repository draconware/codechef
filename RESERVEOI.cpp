#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> arr;

bool check_water(int x,int y){
    if(x==n-1){
        return false;
    }else{
        if((y == 0)||(y == m-1)){
            return false;
        }else if((arr[x][y-1] == 'A')||(arr[x][y+1] == 'A')||(arr[x+1][y] == 'A')){
            return false;
        }else{
            return true;
        }
    }
}

bool check_brick(int x,int y){
    if(x==n-1){
        return true;
    }else if((arr[x+1][y] == 'A')||(arr[x+1][y] == 'W')){
        return false;
    }else{
        return true;
    }
}

bool check_air(int x,int y){
    if(x==n-1){
        return false;
    }else{
        if((y==0)||(y==m-1)||(x==0)){
            return true;
        }else if((arr[x][y-1] == 'W')||(arr[x][y+1] == 'W')){
            return false;
        }else{
            return true;
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int flag=0,flag1=1;
        string temp;
        cin>>n>>m;
        char p;

        for(int i=0;i<n;i++){
            cin>>temp;
            arr.push_back(temp);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 'W'){
                    //cout<<"for i,j --->("<<i<<","<<j<<")"<<"there is ---> "<<arr[i][j]<<endl;
                    if(!check_water(i,j)){
                        cout<<"no"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(arr[i][j] == 'B'){
                    //cout<<"for i,j --->("<<i<<","<<j<<")"<<"there is ---> "<<arr[i][j]<<endl;
                    if(!check_brick(i,j)){
                        cout<<"no"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(arr[i][j] == 'A'){
                    //cout<<"for i,j --->("<<i<<","<<j<<")"<<"there is ---> "<<arr[i][j]<<endl;
                    if(!check_air(i,j)){
                        cout<<"no"<<endl;
                        flag=1;
                        break;
                    }
                }
            }
            if(flag){
                flag1=0;
                break;
            }
        }
        if(flag1){
            cout<<"yes"<<endl;
        }
        arr.clear();
    }
    return 0;
}

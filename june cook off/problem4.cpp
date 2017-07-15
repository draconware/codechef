#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    int n,m,x,y;
    while(t--){
        cin>>n>>m;

        int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=0;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(arr[i][j] == 0){
                    cout<<"observing--- "<<i<<","<<j<<endl;
                    if(i+2<n && j+1<m){
                        if(arr[i+2][j+1] == 0){
                            arr[i+2][j+1]=1;
                            x=i+2;y=j+1;
                        }
                    }else if(i+2<n && j-1>=0){
                        if(arr[i+2][j-1] == 0){
                            arr[i+2][j-1]=1;
                            x=i+2;y=j-1;
                        }
                    }else if(i-2>=0 && j+1<m){
                        if(arr[i-2][j+1] == 0){
                            arr[i-2][j+1]=1;
                            x=i-2;y=j+1;
                        }
                    }else if(i-2>=0 && j-1>=0){
                        if(arr[i-2][j-1] == 0){
                            arr[i-2][j-1]=1;
                            x=i-2;y=j-1;
                        }
                    }else if(i+1<n && j+2<m){
                        if(arr[i+1][j+2] == 0){
                            arr[i+1][j+2]=1;
                            x=i+1;y=j+2;
                        }
                    }else if(i-1>=0 && j+2<m){
                        if(arr[i-1][j+2] == 0){
                            arr[i-1][j+2]=1;
                            x=i-1;y=j+2;
                        }
                    }else if(i+1<n && j-2>=0){
                        if(arr[i+1][j-2] == 0){
                            arr[i+1][j-2]=1;
                            x=i+1;y=j-2;
                        }
                    }else if(i-1>=0 && j-2>=0){
                        if(arr[i-1][j-2] == 0){
                            arr[i-1][j-2]=1;
                            x=i-1;y=j-2;
                        }
                    }else{
                        arr[i][j]=1;
                        continue;
                    }
                    cout<<"got these--- "<<x<<","<<y<<endl;
                    if(x+2<n && y+1<m){
                        if(arr[x+2][y+1] == 0){
                            arr[x+2][y+1] = -1;
                        }
                    }
                    if(x+2<n && y-1>=0){
                        if(arr[x+2][y-1] == 0){
                            arr[x+2][j-1] = -1;
                        }
                    }
                    if(x-2>=0 && y+1<m){
                        if(arr[x-2][y+1] == 0){
                            arr[x-2][y+1] = -1;
                        }
                    }
                    if(x-2>=0 && y-1>=0){
                        if(arr[x-2][y-1] == 0){
                            arr[x-2][y-1] = -1;
                        }
                    }
                    if(x+1<n && y+2<m){
                        if(arr[x+1][y+2] == 0){
                            arr[x+1][y+2] = -1;
                        }
                    }
                    if(x-1>=0 && y+2<m){
                        if(arr[x-1][y+2] == 0){
                            arr[x-1][y+2] = -1;
                        }
                    }
                    if(x+1<n && y-2>=0){
                        if(arr[x+1][y-2] == 0){
                            arr[x+1][y-2] = -1;
                        }
                    }
                    if(x-1>=0 && y-2>=0){
                        if(arr[x-1][y-2] == 0){
                            arr[x-1][y-2] = -1;
                        }
                    }
                }
            }
        }
        int ans=0,temp=0,temp1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1){
                    //cout<<i<<","<<j<<endl;
                    ans++;
                }else if(arr[i][j] == 0){
                    //cout<<i<<","<<j<<endl;
                    temp1++;
                }else if(arr[i][j] == -1){
                    temp++;
                }
            }
        }
        cout<<ans<<","<<temp<<","<<temp1<<endl;
    }
    return 0;
}

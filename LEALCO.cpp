#include<bits/stdc++.h>
using namespace std;

int n,k,m;

int main(){
    int t;
    cin>>t;

    vector<vector<int> > elephants;
    vector<int> temp;

    while(t--){
        cin>>n>>k>>m;

        int arr[n];

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<(n-k+1);i++){
            for(int j=i;j<(k+i);j++){
                temp.push_back(arr[j]);
            }
            elephants.push_back(temp);
            temp.clear();
        }


    }
}

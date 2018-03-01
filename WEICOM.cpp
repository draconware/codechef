#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,k;
		cin>>n>>k;

		int x = ((2*n-1)*n*(n-1))/6;
		if(k>x){cout<<"-1"<<endl;}
		else{
			int arr[n+1][n+1];
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					arr[i][j]=-1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j){arr[i][j]=0;}
					else{
						if(k==0){continue;}
						if(arr[i][j]==-1){
							if(arr[j][i]==-1){arr[i][j]=}
						}
					}
				}
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		int arr[3][3];
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>arr[i][j];
			}
		}
		bool flag=true;
		for(int i=0;i<3;i++){
			for(int j=i+1;j<3;j++){
				int x=0,y=0;
				for(int k=0;k<3;k++){
					if(arr[i][k]>arr[j][k]){x++;}
					else if(arr[i][k]<arr[j][k]){y++;}
				}
				if(x>0 && y>0){flag=false;}
				if((x+y)==0){flag=false;}
			}
		}
		if(flag){cout<<"yes"<<endl;}
		else{cout<<"no"<<endl;}
	}
}
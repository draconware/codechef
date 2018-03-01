#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[19][109];
int val[19][109];

int dp(int x,int y){
	if(y==n){return INT_MAX;}
	if(val[x][y] != -1){return val[x][y];}

	val[x][y] = arr[x][y]+min(dp(x,y+1),min(dp((x+1)%m,y+1),dp((x-1+m)%m,y+1)));
	return val[x][y];
}

void print(int x,int y){
	cout<<x+1;

	int x1,y1,comp=INT_MAX;
	if(y+1 < n){
		if(comp > val[x][y+1]){
			x1=x;y1=y+1;comp=val[x][y+1];
		}
		if(comp > val[(x-1+m)%m][y+1]){
			x1=(x-1+m)%m;y1=y+1;comp=val[(x-1+m)%m][y+1];
		}else if(val[(x-1+m)%m][y+1] == comp){
			if(x1 > (x-1+m)%m){x1=(x-1+m)%m;y1=y+1;}
		}
		if(comp > val[(x+1+m)%m][y+1]){
			x1=(x+1+m)%m;y1=y+1;comp=val[(x+1+m)%m][y+1];
		}else if(comp == val[(x+1+m)%m][y+1]){
			if(x1 > (x+1+m)%m){x1=(x+1+m)%m;y1=y+1;}
		}

		print(x1,y1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		memset(val,-1,sizeof(val));
		int best=INT_MAX;
		for(int i=0;i<m;i++){
			val[i][0] = dp(i,0);
			best = min(best,val[i][0]);
		}
		cout<<bst<<" ";
		int x,y=0;
		for(int i=0;i<m;i++){
			if(val[i][0] == best){
				x=i;break;
			}
		}
		print(x,0);
		cout<<endl;
	}
	return 0;
}
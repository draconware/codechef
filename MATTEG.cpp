#include<bits/stdc++.h>
using namespace std;

int r,c,n;
vector<pair<int,int> > telpairs;
int val[1009][1009][15];
int arr[1009][1009];
bool mark[15];

int dp(int i,int j,int k){
	if(i<0 || i>=r || j<0 || j>=c){return 0;}
	if(k==0){return arr[i][j];}
	if(val[i][j][k]!=-1){return val[i][j][k];}

	int sum=0;
	for(int c=0;c<n;c++){
		int a=telpairs[c].first,b=telpairs[c].second;
		if(!mark[c]){
			mark[c]=true;
			sum = max(sum,arr[i][j] + dp(i+a,j+b,k-1));
			sum = max(sum,arr[i][j] + dp(i+a,j-b,k-1));
			sum = max(sum,arr[i][j] + dp(i-a,j+b,k-1));
			sum = max(sum,arr[i][j] + dp(i-a,j-b,k-1));
			mark[c]=false;
		}
	}
	val[i][j][k]=sum;
	return sum;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		memset(val,-1,sizeof(val));
		memset(mark,0,sizeof(mark));
		telpairs.clear();
		cin>>r>>c>>n;

		int sx,sy;
		cin>>sx>>sy;
		for(int i=0,x,y;i<n;i++){
			cin>>x>>y;
			telpairs.push_back(make_pair(x,y));			
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>arr[i][j];
			}
		}
		cout<<dp(sx,sy,n)<<endl;
	}
}
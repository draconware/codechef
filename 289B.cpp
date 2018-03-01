#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int n,m,d,x;
	cin>>n>>m>>d;

	vector<int> v;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			v.push_back(arr[i][j]);
		}
	}
	sort(v.begin(),v.end());
	int size = (int)v.size();
	
	bool flag=false;
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if((abs(v[i]-v[j]))%d != 0){flag=true;}
		}
	}
	if(flag){cout<<"-1"<<endl;return 0;}
	int best=iNT_MAX;
	if(size%2 == 0){
		int x = v[size/2];
		int y = v[size/2 -1];
		//int best=iNT_MAX;

		int sum=0;
		for(int i=0;i<size;i++){
			sum+=((abs(v[i]-v[x]))/d);
		}
		best=min(best,sum);
		sum=0;
		for(int i=0;i<size;i++){
			sum+=((abs(v[i]-v[y]))/d);
		}
	}else{
		int x = v[size/2];

		int sum=0;
		for(int i=0;i<size;i++){
			sum+=((abs(v[i]-v[x]))/d);
		}
		best=min(best,sum);
	}
	cout<<best<<endl;
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long
int arr[100009];
bool mark[100009];

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
		LL n,k;
		cin>>n>>k;

		LL x = (n*(n+1))/2 - 1;
		LL len = (n-1)/2;

		LL sum=n,y=0;
		while(len--){
			y+=sum;
			sum--;
		}
		y = 2*y;
		if(n%2 == 0){y+=sum;}
		//cout<<x<<" "<<y<<endl;

		if(k<x || k>y){cout<<"-1"<<endl;continue;}

		LL z = n-2;
		sum = 0;
		vector<LL> v;
		while(z>0){
			sum += z;
			v.push_back(sum);
			z-=2;
		}
		//for(int i=0;i<(int)v.size();i++){cout<<v[i]<<" ";}cout<<endl;

		vector<LL>::iterator it = lower_bound(v.begin(),v.end(),k-x);
		int j = it - v.begin(),i;
		if(j==0){
			i = k-x;
		}else{
			i = k-x - v[j-1];
		}
		//cout<<i<<" "<<j<<endl;
		memset(mark,0,sizeof(mark));
		memset(arr,-1,sizeof(arr));
		int idx = n,val=2;
		while(j--){
			mark[val]=true;
			arr[idx] = val;
			val++;idx-=2;
		}
		arr[i+2] = val;
		mark[val]=true;

		idx=1,val=1;
		while(idx<=n && val<=n){
			while(arr[idx]!=-1 && idx<=n){idx++;}
			while(mark[val] && val<=n){val++;}
			//cout<<idx<<" "<<val<<endl;
			arr[idx] = val;
			val++;idx++;
		}
		for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}cout<<endl;
	}
}
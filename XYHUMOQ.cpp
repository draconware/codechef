#include<bits/stdc++.h>
using namespace std;

#define LL long long

string s;
int arr[40];

void convert_binary(LL val,int n){
	arr[0]=1;arr[n-1]=0;
	if(n<=2){return ;}
	LL ext = (int)pow(2.0,n-3);

	int i=1;
	while(ext>0){
		if(val>=ext){val-=ext;arr[i++]=1;}
		else{arr[i++]=0;}
		ext/=2;
	}
}

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
		int n;
		LL u;
		cin>>s>>u;
		n = (int)s.length();
		int org[n+1];
		for(int i=0;i<n;i++){org[i] = s[i]-'0';}

		LL max_limit = (int)pow(2.0,n-2);
		max_limit -= 1;
		int res = n+1;

		LL p = 0;
		for(LL i=0;i<=max_limit;i++){
			convert_binary(i,n);
			//for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
			LL prev_ones=0,curr_ones=0,ans=0,extra=0;
			for(int i=0;i<n;i++){
				if(arr[i]==1){curr_ones++;}
				else{
					extra = extra + ans*curr_ones;
					ans = ans + (prev_ones+curr_ones) + extra;
					prev_ones = prev_ones + curr_ones;
					curr_ones = 0;
				}
			}
			//cout<<ans<<endl;
			p = max(ans,p);
			int diff=0;
			if(ans == u){
				for(int i=0;i<n;i++){if(arr[i]!=org[i]){diff++;}}
				res = min(res,diff);
			}
		}
		cout<<p<<endl;
		if(res<=n-2){cout<<"YES"<<endl;cout<<res<<endl;}
		else{cout<<"NO"<<endl;}
	}
}
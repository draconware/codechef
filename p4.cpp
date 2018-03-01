#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL fact[1000009];
LL M = (LL)(1e9 + 7);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0]=1;
	for(int i=1;i<=1000000;i++){fact[i] = (fact[i-1]*i)%M;}

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		int n = (int)s.length();
		LL arr[30];
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++){arr[s[i]-'a']++;}

		int q;
		cin>>q;

		LL ans=0;
		while(q--){
			int a,b;
			cin>>a>>b;
			a+=b;
			a/=2;
			a-=97;
			//cout<<a<<" ";
			if(arr[a]==0){continue;}
			ans = (ans + fact[arr[a]])%M;
		}
		//cout<<endl;
		cout<<ans<<endl;
	}
}
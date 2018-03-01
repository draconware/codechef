#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL MAX = 8000000;
LL M = 1000000007;

vector<LL> v;
LL val[MAX];

int main(){
	int t;
	cin>>t;

	while(t--){
		v.clear();
		memset(val,0,sizeof(val));
		int n;
		cin>>n;

		for(int x,i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i=n-1;i>=0;i--){
			val[v[i]]=1;
			for(int j=2*v[i];j<=v[n-1];j+=v[i]){
				val[v[i]]+=val[j];
			}
		}
		LL ans=0;
		for(int i=0;i<n;i++){
			ans = (ans+val[i])%M;
		}
		cout<<ans<<endl;
	}
	return 0;
}
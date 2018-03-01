#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = 1000000007;
vector<int> v[100009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	scanf("%d", &t);

	for(int i=1;i<100009;i++){
		for(int j=i;j<100009;j+=i){
			v[j].push_back(i);
		}
	}

	while(t--){
		int n,q;
		scanf("%d %d", &n, &q);

		LL arr[n+1],b[n+1];
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%lld", &arr[i]);
			arr[i] = (arr[i]*arr[i])%M;
		}

		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				b[i] = b[i] + arr[j];
				b[i]%=M;
			}
		}
		//for(int i=1;i<=n;i++){cout<<b[i]<<" ";}cout<<endl;
		while(q--){
			int p,x;
			LL y;
			scanf("%d", &p);
			if(p==1){scanf("%d", &x);printf("%lld\n",b[x]);}
			else{
				scanf("%d %lld", &x, &y);
				for(int i=0;i<v[x].size();i++){
					b[v[x][i]] = (b[v[x][i]] - arr[x] + (y*y)%M + M )%M;
				}
				arr[x] = (y*y)%M;
			}
		}
	}
}
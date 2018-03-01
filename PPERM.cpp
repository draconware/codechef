#include<bits/stdc++.h>
using namespace std;

int MAX = 5000009;

int prime[5000009];
int pperm[5000009];
int M = 1000000007;
bool mark[5000009];

void pre(){
	for(int i=0;i<MAX;i++){mark[i]=false;}

	for(int i=2;i*i<MAX;i++){
		if(!mark[i]){
			for(int j=i*i;j<MAX;j+=i){
				mark[j]=true;
			}
		}
	}
	//k=0;
	prime[0]=0;mark[1]=true;
	for(int i=1;i<MAX;i++){
		prime[i]=(prime[i-1]+(mark[i]?0:1))%M;
		//if(!mark[i]){cout<<i<<" ";}
	}
	//cout<<endl;
	pperm[1]=1;
	for(int i=2;i<MAX;i++){
		pperm[i] = ((1+prime[i])*(pperm[i-1]))%M;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	pre();
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);
		printf("%d\n",pperm[n]);
	}
	return 0;
}
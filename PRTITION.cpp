#include<bits/stdc++.h>
using namespace std;

#define LL long long

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
		LL x,n;
		cin>>x>>n;

		LL val = (n*(n+1))/2;
		val -= x;
		if((val%2 == 1) || n<=3){cout<<"impossible"<<endl;continue;}

		LL y = val/2;
		int mark[n+9];
		mark[x]=2;

		for(int i=n;i>=1;i--){
			if(i==x){continue;}
			if(y>=i){
				if(((y-i)==1 && x==1) || ((y-i)==2 && x==2)){mark[i]=0;}
				else{y-=i;mark[i]=1;}
			}else{
				mark[i]=0;
			}
		}
		int f=0,f1=0;
		for(int i=1;i<=n;i++){
			if(mark[i]==0){f=1;}
			else if(mark[i]==1){f1=1;}
		}
		f = f+f1;
		if(y>=1 || f<2){cout<<"impossible"<<endl;}
		else{for(int i=1;i<=n;i++){cout<<mark[i];}cout<<endl;}
	}
	return 0;
}
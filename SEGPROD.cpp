#include<bits/stdc++.h>
using namespace std;

long long resl[32][1000009],resr[32][1000009];

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
		int n,q;
		long long p;
		cin>>n>>p>>q;

		long long arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}

		int size = (q>>6)+2;
		int b[size];
		for(int i=0;i<size;i++){cin>>b[i];}

		for(int i=0;;i++){
			int x = (1<<i);
			if(x>n){break;}

			int y = x-1;
			long long prod=1;
			for(int j=0;j<n;j++){
				prod = prod*arr[j];
				prod%=p;
				resr[i][j] = prod;
				if((j&y)==y){prod=1;}
			}
			prod=1;
			for(int j=n-1;j>=0;j--){
				prod = prod*arr[j];
				prod%=p;
				resl[i][j]=prod;
				if((j&y)==0){prod=1;}
			}
		}
		int l=0,h=0,prev=0;
		for(int i=0;i<q;i++){
			if((i%64) == 0){
				l = b[i>>6]+prev;
				h = b[(i>>6)+1]+prev;
			}else{
				l+=prev;
				h+=prev;
			}
			l%=n;
			h%=n;
			if(l>h){
				int temp=l;
				l = h;
				h = temp;
			}
			long long x;
			if(l==h){x=arr[l];}
			else{
				int k = 31 - __builtin_clz(l^h);
				x = resl[k][l];
				x *= resr[k][h];
			}
			x = (x+1)%p;
			prev = x;
		}
		cout<<prev<<endl;
	}
}
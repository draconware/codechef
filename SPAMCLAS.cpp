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
		int n;
		LL min_x,max_x;
		cin>>n>>min_x>>max_x;

		LL w[n],b[n];
		for(int i=0;i<n;i++){
			cin>>w[i]>>b[i];
		}

		bool even=true,odd=false;

		bool flag=true;
		for(int i=0;i<n;i++){
			if(flag){
				if(b[i]&1){flag=false;}
				else{flag=true;}
			}else{
				if((w[i]%2) == (b[i]%2)){flag=true;}
				else{flag=false;}
			}
		}
		even = flag;
		flag=true;
		for(int i=0;i<n;i++){
			if(!flag){
				if(b[i]&1){flag=true;}
				else{flag=false;}
			}else{
				if((w[i]%2) == (b[i]%2)){flag=false;}
				else{flag=true;}
			}
		}
		odd=flag;
		LL ans_even=0,ans_odd=0;

		if(even){
			LL x=min_x,y=max_x;
			if(min_x%2 == 1){x++;}
			if(max_x%2 == 1){y--;}
			if(x<=y){ans_even = ans_even + (y-x)/2 + 1;}
		}else{
			LL x=min_x,y=max_x;
			if(min_x%2 == 1){x++;}
			if(max_x%2 == 1){y--;}
			if(x<=y){ans_odd = ans_odd + (y-x)/2 + 1;}
		}
		if(odd){
			LL x=min_x,y=max_x;
			if(min_x%2 == 0){x++;}
			if(max_x%2 == 0){y--;}
			if(x<=y){ans_odd = ans_odd + (y-x)/2 + 1;}
		}else{
			LL x=min_x,y=max_x;
			if(min_x%2 == 0){x++;}
			if(max_x%2 == 0){y--;}
			if(x<=y){ans_even = ans_even + (y-x)/2 + 1;}
		}
		cout<<ans_even<<" "<<ans_odd<<endl;
	}
}
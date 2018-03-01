#include<bits/stdc++.h>
using namespace std;

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
		int n,k,s;
		cin>>n>>k>>s;
	
		if(k>n){cout<<"-1"<<endl;continue;}
	
		int ans=0,c=0;
		bool flag=true;
		for(int i=1;i<=s;i++){
			//cout<<c<<" "<<ans<<endl;
			if(c<k){
				if((i%7) != 0){
					c+=n;ans++;
				}else{
					if(ans == (i-(i/7))){
						flag=false;break;
					}else{
						c+=n;ans++;
					}
				}
			}
			c-=k;
		}
		if(flag){
			cout<<ans<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
}
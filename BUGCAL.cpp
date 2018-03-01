#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;

	while(t--){
		LL a,b,x,y;
		cin>>a>>b;x=a;y=0;
		a = max(a,b);
		b = min(x,b);
		LL res=0;
		while(a>0 || b>0){
			res = (((a%10)+(b%10))%10)*((LL)pow(10,y))+res;
			a/=10;b/=10;y++;
		}
		cout<<res<<endl;
	}
}
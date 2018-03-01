#include<bits/stdc++.h>
using namespace std;

#define LD long double

int main(){
	int t;
	cin>>t;

	while(t--){
		LD u,v,x;
		cin>>u>>v>>x;

		LD ans = x/(u+v);
		printf("%.10LF\n",ans);
	}
	return 0;
}
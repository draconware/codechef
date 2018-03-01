#include<bits/stdC++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long ans=0;
		long long k,a,b;
		cin>>k>>a>>b;

		if((b-a-1) > 10-(b-a+1)){
			ans = ans + (10-(b-a+1));
		}else if((b-a-1) < 10-(b-a+1)){
			ans = ans + b-a-1;
		}
		cout<<ans<<endl;
	}
}
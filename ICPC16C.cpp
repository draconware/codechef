#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int d;
		cin>>d;

		if(d<9){
			cout<<d+1<<endl;
		}else if(d%9 == 0){
			cout<<"1"<<endl;
		}else{
			int x = d - (d/9)*9;
			cout<<x+1<<endl;
		}
	}
	return 0;
}
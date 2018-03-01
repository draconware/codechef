#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int m,x=0,y=0;
		cin>>m;

		int i=(m/3);
		int j=(m%3);
		x+=(i);
		y+=(2*i);
		if(j==1){
			x++;
		}
		if(j==2){
			x++;y++;
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		double n,v1,v2;
		cin>>n>>v1>>v2;

		if((2.0*n)/v2 <= (n*(sqrt(2)))/v1){
			cout<<"Elevator"<<endl;
		}else{
			cout<<"Stairs"<<endl;
		}
	}
}
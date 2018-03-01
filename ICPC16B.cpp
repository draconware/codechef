#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,x,cntbig=0,cntneg=0,cntpos=0;
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>x;
			if(x==1){cntpos++;}
			if(x==-1){cntneg++;}
			if(x>1 || x<-1){cntbig++;}
		}
		if(cntbig>1){
			cout<<"no"<<endl;
		}else if(cntbig==1){
			if(cntneg >= 1){cout<<"no"<<endl;}
			else{cout<<"yes"<<endl;}
		}else if(cntneg>1){
			if(cntpos>=1){cout<<"yes"<<endl;}
			else{cout<<"no"<<endl;}
		}else{
			cout<<"yes"<<endl;
		}
	}
}
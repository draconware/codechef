#include<bits/stdc++.h>
using namespace std;

string s;

bool f(int size){
	int n = (int)s.length();
	for(int i=0;i<=n-size;i++){
		int j=i,k=size+i-1;
		//cout<<j<<","<<k<<endl;
		bool flag=true;
		while(j<=k){
			if(s[j]!=s[k]){flag=false;break;}
			j++;k--;
		}
		if(flag){return true;}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		cin>>s;

		int l=2,h=(int)s.length();
		bool flag=false;
		while(l<=h){
			int m = (l+h)/2;
			//cout<<"eval---- "<<m<<endl;
			if(f(m)){
				flag=true;break;
				l=m+1;
			}else{
				h=m-1;
			}
		}
		if(flag){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
	return 0;
}
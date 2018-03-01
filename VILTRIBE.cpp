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
		string s;
		cin>>s;

		int a=0,b=0,x=0;
		int n = (int)s.length();
		bool flag=false;
		for(int i=0;i<n;i++){
			if(s[i]=='A'){
				if(flag){a+=x;x=0;}
				else{flag=true;x=0;}
			}else if(s[i]=='B'){
				flag=false;
			}else{
				if(flag){
					x++;
				}
			}
		}
		flag=false;x=0;
		for(int i=0;i<n;i++){
			if(s[i]=='B'){
				if(flag){b+=x;x=0;}
				else{flag=true;x=0;}
			}else if(s[i]=='A'){
				flag=false;
			}else{
				if(flag){x++;}
			}
		}
		for(int i=0;i<n;i++){
			if(s[i]=='A'){a++;}
			else if(s[i]=='B'){b++;}
		}
		cout<<a<<" "<<b<<endl;
	}
}
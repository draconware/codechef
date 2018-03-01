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

		int n = (int)s.length();
		int ans=0;
		for(int i=0;i<n;i++){
			int a=0,b=0,c=0,d=0;
			for(int j=i;j<i+4;j++){
				if(s[j]=='c'){a++;}
				else if(s[j]=='h'){b++;}
				else if(s[j]=='e'){c++;}
				else if(s[j]=='f'){d++;}
			}
			if(a==1 && b==1 && c==1 && d==1){ans++;}
		}
		if(ans>0){
			cout<<"lovely "<<ans<<endl;
		}else{
			cout<<"normal"<<endl;
		}
	}
}
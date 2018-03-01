#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string s;cin>>s;
		int x,y;cin>>x>>y;

		int p1=0,p2=0;
		int n = (int)s.length();
		for(int i=0;i<n;i++){
			if(s[i]=='a'){p1++;}
			else{p2++;}
		}

		int cnt1=0,cnt2=0;
		while(p1>0 || p2>0){
			if(p1>=p2){
				if(cnt1<x){
					cout<<"a";
					cnt1++;p1--;cnt2=0;
				}else{
					if(p2>0){
						if(cnt2<y){
							cout<<"b";
							cnt2++;p2--;cnt1=0;
						}else{
							cout<<"*";
							cnt1=0;cnt2=0;
						}
					}else{
						cout<<"*";
						cnt1=0;cnt2=0;
					}
				}
			}else{
				if(cnt2<y){
					cout<<"b";
					cnt2++;cnt1=0;p2--;
				}else{
					if(p1>0){
						if(cnt1<x){
							cout<<"a";
							cnt1++;cnt2=0;p1--;
						}else{
							cout<<"*";
							cnt1=0;cnt2=0;
						}
					}else{
						cout<<"*";
						cnt1=0;cnt2=0;
					}
				}
			}
		}
		cout<<endl;
	}
}
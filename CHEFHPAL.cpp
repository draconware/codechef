#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin>>t;
 
	while(t--){
		int n,a;
		cin>>n>>a;
 
		if(a>=n){
			cout<<"1 ";
			for(int i=0;i<n;i++){
				char c = 'a'+i;
				cout<<c;
			}
		}else{
			if(a==1){
				cout<<n<<" ";
				for(int i=0;i<n;i++){
					cout<<"a";
				}
			}else if(a==2){
				if(n==3){cout<<"2 aab";}
				else if(n==4){cout<<"2 aabb";}
				else if(n==5){cout<<"3 aabab";}
				else if(n==6){cout<<"3 aababb";}
				else if(n==7){cout<<"3 aaababb";}
				else if(n==8){cout<<"3 aaababbb";}
				else{
					cout<<"4 ";
					cout<<"aaaabbab";
					n-=8;
					int x = (n/6);
					for(int i=0;i<x;i++){cout<<"aabbab";}
					n = n - (x*6);

					if(n>2){
						cout<<"aa";
						n-=2;
						if(n>2){
							cout<<"bb";
							n-=2;
							if(n==2){cout<<"ab";}
							if(n==1){cout<<"a";}
						}else{
							for(int i=0;i<n;i++){
								cout<<"b";
							}
						}
					}else{
						for(int i=0;i<n;i++){
							cout<<"a";
						}
					}
				}
			}else{
				cout<<"1 ";
				int x = (n/a);
				for(int i=0;i<x;i++){
					for(int j=0;j<a;j++){
						char c = 'a'+j;
						cout<<c;
					}
				}
				for(int i=0;i<(n-(x*a));i++){
					char c = 'a'+i;
					cout<<c;
				}
			}
		}
		cout<<endl;
	}
}
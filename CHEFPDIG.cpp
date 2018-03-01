#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		int n = (int)s.length();
		int a[10],b[30];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

		for(int i=0;i<n;i++){
			a[s[i]-'0']++;
		}
		int p = 6;
		for(int i=5;i<=9;i++){
			int j = p*10+i;
			if(i==p){
				b[j-65] += (a[i]*(a[i]-1))/2;
			}else{
				b[j-65] += (a[i]*a[p]);
			}
		}
		p++;
		for(;p<9;p++){
			for(int i=0;i<=9;i++){
				int j = p*10+i;
				if(i==p){
					b[j-65] += (a[i]*(a[i]-1))/2;
				}else{
					b[j-65] += (a[i]*a[p]);
				}
			}
		}
		b[25] = (a[9]*a[0]);
		for(int i=0;i<26;i++){
			if(b[i]>0){
				char c = 'A'+i;
				cout<<c;
				//b[i]--;
			}
		}
		cout<<endl;
	}
	return 0;
}
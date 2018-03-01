#include<bits/stdc++.h>
using namespace std;

int mark[200009];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--){
		//cout<<"executed"<<endl;
		int n,k;
		cin>>n>>k;
		memset(mark,0,sizeof(mark));

		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			mark[a]=1;
		}
		int c=0;
		while(k>0){
			if(mark[c]==0){mark[c]=1;k--;}
			c++;
		}
		int ans=0;
		while(mark[ans]){ans++;}
		cout<<ans<<endl;
	}
	return 0;
}
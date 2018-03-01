#include<bits/stdc++.h>
using namespace std;

int arr[1000][7];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	

	int k=0;
	for(int a=1;a<=6;a++){
		for(int b=1;b<=6;b++){
			for(int c=1;c<=6;c++){
				for(int d=1;d<=6;d++){
					for(int e=1;e<=6;e++){
						for(int f=1;f<=6;f++){
							if(a!=b && a!=c && a!=d && a!=e && a!=f && c!=b && d!=b && e!=b && f!=b && c!=d && c!=e && c!=f && d!=e && d!=f && e!=f){
								arr[k][1] = a;arr[k][2]=b;arr[k][3]=c;arr[k][4]=d;arr[k][5]=e;arr[k][6]=f;
								k++;
							}
						}
					}
				}
			}
		}
	}
	int opp[7];
	opp[1]=6;opp[2]=3;opp[3]=2;opp[4]=5;opp[5]=4;opp[6]=1;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int inp[n];
		for(int i=0;i<n;i++){cin>>inp[i];}
		bool flag;
		for(int i=0;i<k;i++){
			int a = inp[0];
			flag=true;
			int pos[7],val[7];
			for(int j=1;j<=6;j++){pos[arr[i][j]]=j;}
			for(int j=1;j<=6;j++){val[j]=arr[i][j];}
			for(int j=1;j<n;j++){
				if(inp[j]==val[opp[pos[a]]] || inp[j]==a){flag=false;break;}
				a = inp[j];
			}
			if(flag){
				for(int j=1;j<=6;j++){cout<<val[opp[pos[j]]]<<" ";}cout<<endl;
				break;
			}
		}
		if(!flag){cout<<"-1"<<endl;}
	}
}
#include<bits/stdc++.h>
using namespace std;

vector<int> v[100009];
int arr[100009];
int val[100009];

void assign(int idx,int c){
	if(val[c]!=-1){return ;}
	while(val[c] != -1){
		if(val[c] > idx){
			int temp = val[c];
			val[c]=idx;
			v[idx]=c;
			arr[idx]=c;
			idx=temp;
		}
		c++;
	}
	val[c]=idx;
	arr[idx]=c;
	return ;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;
		memset(arr,0.sizeof(arr));
		memset(val,-1,sizeof(val));

		for(int i=0;i<=n;i++){v[i].clear();}
		for(int i=0,x,y;i<m;i++){
			cin>>x>>y;
			v[x].push_back(y);
		}
		for(int i=0;i<=n;i++){
			sort(v[i].begin(),v[i].end());
		}
		int c=1;
		for(int i=0;i<v[0].size();i++){
			val[c]=v[0][i];
			arr[v[0][i]]=c++;
		}
		for(int i=1;i<=n;i++){
			assign(i,1);
			int c=1;
			for(int j=0;j<v[i].size();j++){
				assign(j,c);
			}
		}
		bool mark[100009];
		bool flag=true;
		memset(mark,0,sizeof(mark));
		int dist=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==0){flag=false;break;}
			if(mark[arr[i]]==0){dist++;}
			mark[arr[i]]++;
		}
		if()
	}
}
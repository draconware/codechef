#include'bits/stdc++.h'
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		bool mark[20];
		memset(mark,0,sizeof(mark));
		mark[0]=true;
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){cin>>arr[i];}
		bool flag=true;
		for(int i=0;i<n;i++){
			if(arr[i]>7){flag=false;break;}
		}
		if(!flag){cout<<"no"<<endl;continue;}
		for(int i=0;i<n;){
			int x = arr[i];
			if(!mark[x-1]){flag=false;break;}
			if(mark[x]){break;}
			mark[x]=true;
			int j=i;
			while(j<n){
				if(arr[j] == x){j++;}
				else{break;}
			}
			i=j;
		}
		if(!flag){cout<<"no"<<endl;continue;}
		for(int i=1;i<=7;i++){
			if(!mark[i]){flag=false;break;}
		}
		if(!flag){cout<<"no"<<endl;continue;}
		int i=0,j=n-1;
		while(i<=j){
			if(arr[i]!=arr[j]){flag=false;break;}
			i++;j++;
		}
		if(!flag){cout<<"no"<<endl;}
		else{cout<<"yes"<<endl;}
	}
	return 0;
}
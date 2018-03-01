#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int c,x;
		vector<int> temp,v;
		while(scanf("%d", &x) != EOF){
			temp.push_back(x);
			c++;
		}
		bool flag=false;
		for(int i=0;i<c;i++){
			if(temp[i] != c-1){v.push_back(temp[i]);}
			else{
				if(flag){v.push_back(temp[i]);}
				else{flag=true;}
			}
		}
		int maxi=-1;
		for(int i=0;i<v.size();i++){
			maxi = max(maxi,v[i]);
		}
		cout<<maxi<<endl;
	}
	return 0;
}
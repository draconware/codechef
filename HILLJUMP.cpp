#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
	int n,q;
	cin>>n>>q;

	vector<LL> v;
	LL x;
	for(int i=0;i<n;i++){cin>>x;v.push_back(x);}
	int a,b,c;
	LL d,curr;
	while(q--){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			int j;
			for(int i=b;i<=n;){
				if(cin==0){break;}
				curr = v[i-1];
				j = i+1;
				while(j<=n && curr>=v[j-1]){
					j++;
				}
				if(j>n){j=n;break;}
				if(j-i > 100){j=i;break;}
				i=j;c--;
			}
			cout<<j<<endl;
		}else{
			cin>>b>>c;
			cin>>d;
			for(int i=b;i<=c;i++){
				v[i-1]+=d;
			}
		}
	}
	return 0;
}
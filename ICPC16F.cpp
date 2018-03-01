#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		vector<pair<int,int> > res;
		int n,m,d,D,k;
		cin>>n>>m>>d>>D;k=m;

		int x = n*d;
		int y = n*D;
		//cout<<x<<","<<y<<endl;
		if(m>=x && m<=y){
			for(int i=1;i<=n;i++){
				int c=d,j=i;
				while(c--){
					if(j>n){res.push_back(make_pair(i,j%n));}
					else{res.push_back(make_pair(i,j));}
					j++;
				}
			}

			if(m>x){
				k-=x;
				for(int i=1;i<=n;i++){
					int l=d+1,j=d+i;
					if(d+i>n){j=(d+i)%n;}
					while(l<=D){
						if(k==0){break;}
						res.push_back(make_pair(i,j));
						j++;l++;k--;
						if(j>n){j%=n;}
					}
				}
			}
			for(int i=0;i<res.size();i++){
				cout<<res[i].first <<" "<< res[i].second<<endl;
			}
		}else{
			cout<<"-1"<<endl;
		}
	}
}
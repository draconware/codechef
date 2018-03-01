#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	while(a>0){
		int t=a;
		a = b%a;
		b = t;
	}
	return b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<pair<int,int> > points;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;

			points.push_back(make_pair(x,y));
		}
		int m = (int)(n/10);
		int bx = points[0].first,by = points[0].second;
		for(int i=2;i<n && m>0;i++){
			int nx = points[i].first;
			int ny = points[i].second;

			int x = nx-bx;
			int y = ny-by;
			int g = gcd(abs(x),abs(y));
			if(g==1){continue;}
			x = x/g;
			y = y/g;
			while(g>1 && m>0){
				cout<<bx+x<<" "<<by+y<<endl;
				g--;m--;
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<pair<LL,LL> > points;
bool red[2009],blue[2009];
int inf = 3000;

int decide(LL x,LL y){
	if(x>=0 && y>=0){return 1;}
	else if(x<=0 && y>=0){return 2;}
	else if(x<=0 && y<=0){return 3;}
	else{return 4;}
}

int main(){
	int t;
	cin>>t;

	while(t--){
		points.clear();
		memset(red,0,sizeof(red));
		memset(blue,0,sizeof(blue));

		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			LL a,b;cin>>a>>b;
			points.push_back(make_pair(a,b));
			red[i]=true;
		}
		for(int i=0;i<m;i++){
			LL a,b;cin>>a>>b;
			points.push_back(make_pair(a,b));
			blue[i+n]=true;
		}

		int ans=inf;
		for(int i=0;i<n+m;i++){
			bool quadrant[n+m];
			memset(arr,0,sizeof(arr));
			for(int j=0;j<n+m;j++){
				LL xn = points[j].first-points[i].first;
				LL yn = points[j].second-points[i].second;
				if(i!=j){quadrant[j]=decide(xn,yn);}
			}

			int red1=0,blue1=0,red2=0,blue2=0;
			for(int j=0;j<n+m;j++){
				if(i==j){continue;}
				if(quadrant[j]==1 || quadrant[j]==2){
					if(red[j]){red1++;}
					else{blue1++;}
				}else{
					if(red[j]){red2++;}
					else{blue2++;}
				}
			}
			vector<pair<int,int> > res;
			for(int j=0;j<n+m;j++){
				res.push_back(make_pair(quadrant[j],j));
			}
			sort(quadrant.begin(),quadrant.end());

			for(int j=0;j<n+m;j++){
				int quad = res[j].first;
				int idx = res[j].second;
				
				
			}
		}
	}
}
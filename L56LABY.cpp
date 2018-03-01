#include<bits/stdc++.h>
using namespace std;

int l[4]={-1,1,0,0};
int r[4]={0,0,-1,1};
int n,m;

bool chk(int i,int j){
	if((i<0) || (i>=n) || (j<0) || (j>=m)){return false;}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		scanf("%d", &m);

		int arr[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d", &arr[i][j]);
			}
		}

		vector<pair<int,pair<int,int> > > v;
		int level[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j] > 0){
					v.push_back(make_pair(arr[i][j],make_pair(i,j)));
				}
				level[i][j] = -1;
			}
		}

		char res[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				res[i][j] = 'N';
			}
		}
		bool mark[n][m];
		memset(mark,0,sizeof(mark));

		int len = (int)v.size();
		for(int i=0;i<len;i++){
			int x = v[i].second.first;
			int y = v[i].second.second;

			if(level[x][y] >= arr[x][y]){continue;}
			level[x][y] = arr[x][y];
			queue<pair<pair<int,int>,int> > q;
			q.push(make_pair(make_pair(x,y),level[x][y]));

			while(!q.empty()){
				pair<pair<int,int>,int> p = q.front();
				x = p.first.first;
				y = p.first.second;
				int w = p.second;
				q.pop();

				if(w<0){continue;}
				else if(w==0){res[x][y]='Y';continue;}
				else{res[x][y] = 'Y';}

				for(int j=0;j<4;j++){
					int nx = x+l[j];
					int ny = y+r[j];

					if(!chk(nx,ny)){continue;}
					if(arr[nx][ny] == -1){continue;}
					if(level[nx][ny] >= (w-1)){
						continue;
					}else{
						level[nx][ny] = (w-1);
						q.push(make_pair(make_pair(nx,ny),w-1));
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j] == -1){res[i][j] = 'B';}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%c", res[i][j]);
			}
			printf("\n");
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define M 1000000007

void range_update(int st[],int s,int e,int idx,int l,int r,int val){
	if(st[idx]>0 && s!=e){
		st[2*idx+1] = (st[2*idx+1]+st[idx])%M;
		st[2*idx+2] = (st[2*idx+2]+st[idx])%M;
		st[idx]=0;
	}
	if(s>r || l>e){return ;}
	if(l<=s && r>=e){
		st[idx] = (st[idx]+val)%M;return ;
	}
	int mid = (s+e)/2;
	range_update(st,s,mid,2*idx+1,l,r,val);
	range_update(st,mid+1,e,2*idx+2,l,r,val);
}

void point_update(int st[],int s,int e,int idx,int p,int val){
	if(st[idx]>0 && s!=e){
		st[2*idx+1] = (st[2*idx+1]+st[idx])%M;
		st[2*idx+2] = (st[2*idx+2]+st[idx])%M;
		st[idx]=0;
	}
	if(s>p || e<p){return ;}
	if(s==p && s==e){
		st[idx] = val;return ;
	}
	int mid = (s+e)/2;
	point_update(st,s,mid,2*idx+1,p,val);
	point_update(st,mid+1,e,2*idx+2,p,val);
}

int point_query(int st[],int s,int e,int idx,int p){
	if(st[idx]>0 && s!=e){
		st[2*idx+1] = (st[2*idx+1]+st[idx])%M;
		st[2*idx+2] = (st[2*idx+2]+st[idx])%M;
		st[idx]=0;
	}
	if(s>p || e<p){return 0;}
	if(s==p && s==e){
		return st[idx]%M;
	}
	int mid = (s+e)/2;
	int left = point_query(st,s,mid,2*idx+1,p);
	int right = point_query(st,mid+1,e,2*idx+2,p);
	return (left+right)%M;
}

void settle_down(int st[],int s,int e,int idx){
	if(st[idx]>0 && s!=e){
		st[2*idx+1] = (st[2*idx+1]+st[idx])%M;
		st[2*idx+2] = (st[2*idx+2]+st[idx])%M;
		st[idx]=0;
	}
	if(s==e){return ;}
	int m = (s+e)/2;
	settle_down(st,s,m,2*idx+1);
	settle_down(st,m+1,e,2*idx+2);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;

	int st1[4*100010],st2[4*100010];
	while(t--){
		memset(st1,0,sizeof(st1));
		memset(st2,0,sizeof(st2));

		int n,m;
		cin>>n>>m;

		vector<pair<int,pair<int,int> > > v;
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			v.push_back(make_pair(a,make_pair(b,c)));
		}
		for(int i=m-1;i>=0;i--){
			int a = v[i].first,b = v[i].second.first,c = v[i].second.second;
			if(a==1){
				int x = point_query(st1,0,m-1,0,i);
				point_update(st1,0,m-1,0,i,(x+1)%M);
			}else{
				int x = point_query(st1,0,m-1,0,i);
				range_update(st1,0,m-1,0,b-1,c-1,(x+1)%M);
				point_update(st1,0,m-1,0,i,0);
			}
		}
		settle_down(st1,0,m-1,0);
		//for(int i=0;i<)
		for(int i=0;i<m;i++){
			int a = v[i].first,b = v[i].second.first,c = v[i].second.second;
			if(a==1){
				int x = point_query(st1,0,m-1,0,i);
				range_update(st2,0,n-1,0,b-1,c-1,(x)%M);
			}
		}
		settle_down(st2,0,n-1,0);
		for(int i=0;i<n;i++){
			int x = point_query(st2,0,n-1,0,i);
			cout<<x%M<<" ";
		}
		cout<<endl;
	}
}
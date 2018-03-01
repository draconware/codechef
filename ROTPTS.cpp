#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = 1000000007;

struct point{
	LL x,y;
	int angle;
};

struct coordinate{
	LL a1,b1,c1,a2,b2,c2;
};

struct point arr[100009];
struct coordinate st[4*100009];
struct coordinate X;

void update(int s,int e,int idx,int pos,int _x,int _y,int angle){
	if(s>e || s>pos || pos>e){return ;}
	if(s==e && s==pos){
		arr[s].x=_x;arr[s].y=_y;
		arr[s].angle = angle;
		if(arr[s].angle==0){
			st[idx].a1=1;st[idx].a2=0;st[idx].b1=0;st[idx].b2=1;st[idx].c1=0;st[idx].c2=0;
		}else if(arr[s].angle==90){
			st[idx].a1=0;st[idx].a2=1;st[idx].b1=(-1+M)%M;st[idx].b2=0;st[idx].c1=(arr[s].x+arr[s].y+M)%M;st[idx].c2=(arr[s].y-arr[s].x+M)%M;
		}else if(arr[s].angle==180){
			st[idx].a1=(-1+M)%M;st[idx].b1=0;st[idx].c1=(2*arr[s].x+M)%M;st[idx].a2=0;st[idx].b2=(-1+M)%M;st[idx].c2=(2*arr[s].y+M)%M;
		}else{
			st[idx].a1=0;st[idx].b1=1;st[idx].c1=(arr[s].x-arr[s].y+M)%M;st[idx].a2=(-1+M)%M;st[idx].b2=0;st[idx].c2=(arr[s].x+arr[s].y+M)%M;
		}
		return ;
	}
	int m = (s+e)/2;
	update(s,m,2*idx,pos,_x,_y,angle);
	update(m+1,e,2*idx+1,pos,_x,_y,angle);

	st[idx].a1 = ((st[2*idx+1].a1*st[2*idx].a1 +M)%M + (st[2*idx+1].b1*st[2*idx].a2 +M)%M)%M;
	st[idx].a2 = ((st[2*idx+1].a2*st[2*idx].a1 +M)%M + (st[2*idx+1].b2*st[2*idx].a2 +M)%M)%M;
	st[idx].b1 = ((st[2*idx+1].a1*st[2*idx].b1 +M)%M + (st[2*idx+1].b1*st[2*idx].b2 +M)%M)%M;
	st[idx].b2 = ((st[2*idx+1].a2*st[2*idx].b1 +M)%M + (st[2*idx+1].b2*st[2*idx].b2 +M)%M)%M;
	st[idx].c1 = ((st[2*idx+1].a1*st[2*idx].c1 +M)%M + (st[2*idx+1].b1*st[2*idx].c2 +M)%M + st[2*idx+1].c1 +M)%M;
	st[idx].c2 = ((st[2*idx+1].a2*st[2*idx].c1 +M)%M + (st[2*idx+1].b2*st[2*idx].c2 +M%M) + st[2*idx+1].c2 +M)%M;
}

struct coordinate query(int s,int e,int l,int r,int idx){
	if(l>r || s>e || l>e || s>r){return X;}
	if(l<=s && r>=e){
		return st[idx];
	}
	int m = (s+e)/2;
	struct coordinate left = query(s,m,l,r,2*idx);
	struct coordinate right = query(m+1,e,l,r,2*idx+1);
	struct coordinate res;

	res.a1 = ((right.a1*left.a1 +M)%M + (right.b1*left.a2 +M)%M)%M;
	res.a2 = ((right.a2*left.a1 +M)%M + (right.b2*left.a2 +M)%M)%M;
	res.b1 = ((right.a1*left.b1 +M)%M + (right.b1*left.b2 +M)%M)%M;
	res.b2 = ((right.a2*left.b1 +M)%M + (right.b2*left.b2 +M)%M)%M;
	res.c1 = ((right.a1*left.c1 +M)%M + (right.b1*left.c2 +M)%M + right.c1 +M)%M;
	res.c2 = ((right.a2*left.c1 +M)%M + (right.b2*left.c2 +M%M) + right.c2 +M)%M;
	return res;
}

void build(int s,int e,int idx){
	if(s>e){return ;}
	if(s==e){
		if(arr[s].angle==0){
			st[idx].a1=1;st[idx].a2=0;st[idx].b1=0;st[idx].b2=1;st[idx].c1=0;st[idx].c2=0;
		}else if(arr[s].angle==90){
			st[idx].a1=0;st[idx].a2=1;st[idx].b1=(-1+M)%M;st[idx].b2=0;st[idx].c1=(arr[s].x+arr[s].y+M)%M;st[idx].c2=(arr[s].y-arr[s].x+M)%M;
		}else if(arr[s].angle==180){
			st[idx].a1=(-1+M)%M;st[idx].b1=0;st[idx].c1=(2*arr[s].x+M)%M;st[idx].a2=0;st[idx].b2=(-1+M)%M;st[idx].c2=(2*arr[s].y+M)%M;
		}else{
			st[idx].a1=0;st[idx].b1=1;st[idx].c1=(arr[s].x-arr[s].y+M)%M;st[idx].a2=(-1+M)%M;st[idx].b2=0;st[idx].c2=(arr[s].x+arr[s].y+M)%M;
		}
		return ;
	}
	int m = (s+e)/2;
	build(s,m,2*idx);
	build(m+1,e,2*idx+1);
	st[idx].a1 = ((st[2*idx+1].a1*st[2*idx].a1 +M)%M + (st[2*idx+1].b1*st[2*idx].a2 +M)%M)%M;
	st[idx].a2 = ((st[2*idx+1].a2*st[2*idx].a1 +M)%M + (st[2*idx+1].b2*st[2*idx].a2 +M)%M)%M;
	st[idx].b1 = ((st[2*idx+1].a1*st[2*idx].b1 +M)%M + (st[2*idx+1].b1*st[2*idx].b2 +M)%M)%M;
	st[idx].b2 = ((st[2*idx+1].a2*st[2*idx].b1 +M)%M + (st[2*idx+1].b2*st[2*idx].b2 +M)%M)%M;
	st[idx].c1 = ((st[2*idx+1].a1*st[2*idx].c1 +M)%M + (st[2*idx+1].b1*st[2*idx].c2 +M)%M + st[2*idx+1].c1 +M)%M;
	st[idx].c2 = ((st[2*idx+1].a2*st[2*idx].c1 +M)%M + (st[2*idx+1].b2*st[2*idx].c2 +M%M) + st[2*idx+1].c2 +M)%M;
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	X = {1,0,0,0,1,0};
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		LL a,b;
		int c;
		cin>>a>>b>>c;
		arr[i].x = a;
		arr[i].y = b;
		arr[i].angle = c;
	}

	build(0,n-1,0);
	int q;
	cin>>q;

	while(q--){
		int type;
		cin>>type;

		if(type==1){
			LL x,y;
			int l,r;
			struct coordinate res = query(0,n-1,l,r,0);
			LL ans1 = ((x*res.a1 +M)%M + (y*res.b1 +M)%M + (res.c1)%M +M)%M;
			LL ans2 = ((x*res.a2 +M)%M + (y*res.b2 +M)%M + (res.c2)%M +M)%M;
			cout<<ans1<<" "<<ans2<<endl;
		}else{
			int u;
			LL _x,_y;
			int b;
			cin>>u>>_x>>_y>>b;
			update(0,n-1,0,u,_x,_y,b);
		}
	}
}
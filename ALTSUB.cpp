#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL M = 1000000007;

LL arr[100009];
LL st1[4*100009];
LL st2[4*100009];

LL power(int y){
	LL res=1,x=2;
	while(y>0){
		if(y%2==1){res = (res*x)%M;}
		y/=2;
		x = (x*x)%M;
	}
	return res;
}

void build1(int s,int e,int idx){
	if(s>e){return;}
	if(s==e){
		st1[idx] = (arr[s]*arr[s])%M;
	}else{
		int m = (s+e)/2;
		build1(s,m,2*idx+1);
		build1(m+1,e,2*idx+2);
		st1[idx] = (st1[2*idx+1]+st1[2*idx+2])%M;
	}
}

void build2(int s,int e,int idx){
	if(s>e){return;}
	if(s==e){
		st2[idx] = (arr[s]*arr[s+1])%M;
	}else{
		int m = (s+e)/2;
		build2(s,m,2*idx+1);
		build2(m+1,e,2*idx+2);
		st2[idx] = (st2[2*idx+1]+st2[2*idx+2])%M;
	}
}

void update1(int s,int e,int idx,int p){
	if(p>e || p<s){return;}
	if(s==e && s==p){
		st1[idx] = (arr[s]*arr[s])%M;
	}else{
		int m = (s+e)/2;
		update1(s,m,2*idx+1,p);
		update1(m+1,e,2*idx+2,p);
		st1[idx] = (st1[2*idx+1]+st1[2*idx+2])%M;
	}
}

void update2(int s,int e,int idx,int p){
	if(p>e || p<s){return;}
	if(s==e && p==e){
		st2[idx] = (arr[s]*arr[s+1])%M;
	}else{
		int m = (s+e)/2;
		update2(s,m,2*idx+1,p);
		update2(m+1,e,2*idx+2,p);
		st2[idx] = (st2[2*idx+1]+st2[2*idx+2])%M;
	}
}

LL query1(int s,int e,int l,int r,int idx){
	if(s>e || s>r || l>e){return 0;}
	if(l<=s && r>=e){return st1[idx];}

	int m = (s+e)/2;
	LL lft = query1(s,m,l,r,2*idx+1);
	LL rgt = query1(m+1,e,l,r,2*idx+2);
	return (lft+rgt)%M;
}

LL query2(int s,int e,int l,int r,int idx){
	if(s>e || s>r || l>e){return 0;}
	if(l<=s && r>=e){return st2[idx];}

	int m = (s+e)/2;
	LL lft = query2(s,m,l,r,2*idx+1);
	LL rgt = query2(m+1,e,l,r,2*idx+2);
	return (lft+rgt)%M;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){cin>>arr[i];}
	build1(0,n-1,0);
	build2(0,n-2,0);
	//for(int i=0;i<7;i++){cout<<st1[i]<<" ";}cout<<endl;
	//for(int i=0;i<5;i++){cout<<st2[i]<<" ";}cout<<endl;

	while(m--){
		int x;
		cin>>x;
		if(x==1){
			int a;
			LL b;
			cin>>a>>b;
			arr[a-1]=b;
			update1(0,n-1,0,a-1);
			update2(0,n-2,0,a-1);
			update2(0,n-2,0,a-2);
		}else{
			int a,b;
			cin>>a>>b;
			LL x1 = power(b-a)%M;
			LL x2 = query1(0,n-1,a-1,b-1,0)%M;
			LL x3 = query2(0,n-2,a-1,b-2,0)%M;
			//cout<<x1<<" "<<x2<<" "<<x3<<endl;
			LL ans = (x1*(x2-x3+M)%M)%M;
			cout<<ans<<endl;
		}
	}
}
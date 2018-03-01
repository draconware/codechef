#include<bits/stdc++.h>
using namespace std;

#define LL long long

struct node{
	LL val,suffix,prefix,suffix_count,prefix_count,flag;
};

struct node st[4*500009];

struct node constant;

void build(int s,int e,int i){
	if(s>e){return ;}
	if(s==e){
		st[i].val=0;st[i].suffix=0;st[i].prefix=0;st[i].flag=0;
		st[i].prefix_count=1;st[i].suffix_count=1;
		return ;
	}
	int m = s+(e-s)/2;
	build(s,m,2*i);
	build(m+1,e,2*i+1);
	st[i].val=0;st[i].suffix=0;st[i].prefix=0;st[i].flag=0;
	st[i].prefix_count = st[2*i].prefix_count + st[2*i+1].prefix_count;
	st[i].suffix_count = st[2*i].suffix_count + st[2*i+1].suffix_count;
}

void update(int s,int e,int pos,int value,int i){
	if(s>e || pos<s || pos>e){return ;}
	if(s==e && s==pos){
		if(value==0){
			st[i].val=0;st[i].suffix=0;st[i].prefix=0;st[i].flag=0;
			st[i].prefix_count=1;st[i].suffix_count=1;
		}else if(value==-1){
			st[i].val=0;st[i].suffix=0;st[i].prefix=0;st[i].flag=1;
			st[i].prefix_count=0;st[i].suffix_count=0;
		}else{
			st[i].val=1;st[i].suffix=1;st[i].prefix=1;st[i].flag=0;
			st[i].prefix_count=1;st[i].suffix_count=1;
		}
		return ;
	}
	int m = s + (e-s)/2;
	update(s,m,pos,value,2*i);
	update(m+1,e,pos,value,2*i+1);
	st[i].val = st[2*i].val + st[2*i+1].val + ((st[2*i].suffix)*(st[2*i+1].prefix_count)) + ((st[2*i].suffix_count)*(st[2*i+1].prefix)) - ((st[2*i].suffix)*(st[2*i+1].prefix));
	if(st[2*i].flag == 1){st[i].prefix = st[2*i].prefix;st[i].prefix_count = st[2*i].prefix_count;}
	else{
		if(st[2*i].prefix > 0){st[i].prefix = st[2*i].prefix + st[2*i+1].prefix_count;}
		else{st[i].prefix = st[2*i+1].prefix;}
		st[i].prefix_count = st[2*i].prefix_count + st[2*i+1].prefix_count;
	}
	if(st[2*i+1].flag == 1){st[i].suffix = st[2*i+1].suffix;st[i].suffix_count = st[2*i+1].suffix_count;}
	else{
		if(st[2*i+1].suffix > 0){st[i].suffix = st[2*i+1].suffix + st[2*i].suffix_count;}
		else{st[i].suffix = st[2*i].suffix;}
		st[i].suffix_count = st[2*i].suffix_count + st[2*i+1].suffix_count;
	}
	st[i].flag = max(st[2*i].flag,st[2*i+1].flag);
}

struct node query(int s,int e,int l,int r,int i){
	if(s>e || s>r || l>e){
		return constant;
	}
	if(l<=s && r>=e){
		return st[i];
	}
	int m = s + (e-s)/2;
	struct node left = query(s,m,l,r,2*i);
	struct node right = query(m+1,e,l,r,2*i+1);
	struct node ans;
	ans.val = left.val + right.val + ((left.suffix)*(right.prefix_count)) + ((right.prefix)*(left.suffix_count)) - ((left.suffix)*(right.prefix));
	if(left.flag == 1){ans.prefix = left.prefix;ans.prefix_count = left.prefix_count;}
	else{
		if(left.prefix > 0){ans.prefix = left.prefix + right.prefix_count;}
		else{ans.prefix = right.prefix;}
		ans.prefix_count = left.prefix_count + right.prefix_count;
	}
	if(right.flag == 1){ans.suffix = right.suffix;ans.suffix_count = right.suffix_count;}
	else{
		if(right.suffix > 0){ans.suffix = right.suffix + left.suffix_count;}
		else{ans.suffix = left.suffix;}
		ans.suffix_count = left.suffix_count + right.suffix_count;
	}
	ans.flag = max(left.flag,right.flag);
	return ans;
}

int main(){
	#ifndef ONLNE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif 
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,q,l,r;
	cin>>n>>q>>l>>r;

	constant.val=0;constant.suffix=0;constant.prefix_count=0;constant.prefix=0;constant.suffix_count=0;constant.flag=0;
	build(1,n,1);

	while(q--){
		int a,x,y;
		cin>>a>>x>>y;

		if(a==1){
			if(y>=l && y<=r){y=1;}
			else if(y<l){y=0;}
			else{y=-1;}
			update(1,n,x,y,1);
		}else{
			struct node ans = query(1,n,x,y,1);
			cout<<ans.val<<endl;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

#define LL long long


struct node{
	LL f,s;
};

LL M = 1000000007;
LL arr[1000009];
struct node st[3*1000009];
struct node ans;

void build(LL s,LL e,LL i){
	if(s==e){
		st[i].f = arr[s];
		st[i].s = arr[s];
	}else{
		LL m = (s+e)/2;
		build(s,m,2*i+1);
		build(m+1,e,2*i+2);  
		st[i].f = max(st[2*i+1].f,st[2*i+2].f);
		st[i].s = max(st[2*i+1].s,st[2*i+2].s);
	}
}

void query(LL l,LL h,LL s,LL e,LL i){
	if(l>e || h<s){return;}
	if(l<=s && h>=e){ans.f = max(ans.f,st[i].f);ans.s = min(ans.s,st[i].s); return;}

	LL m = (s+e)/2;
	query(l,h,s,m,2*i+1);
	query(l,h,m+1,e,2*i+2);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	LL n;
	cin>>n;
	//cout<<"executed"<<endl;
	for(LL i=0;i<n;i++){cin>>arr[i];}
	//cout<<"executed"<<endl;
	build(0,n-1,0);
	//cout<<"executed"<<endl;
	LL val1[n+9],val2[n+9];
	memset(val1,0,sizeof(val1));
	memset(val2,0,sizeof(val2));
	for(LL i=1;i<n;i++){
		val1[i] = (val1[i] + val1[i-1]);
		val1[i]%=M;
		for(LL j=1;j<=i;j++){
			ans.f = INT_MIN;ans.s = INT_MAX;
			query(i-1,j-1,0,n-1,0);
			val1[i] = val1[i] + ans.f;
			val1[i]%=M;
		}
	}
	for(int i=1;i<n;i++){cout<<val1[i]<<" ";}
	cout<<endl;
	//cout<<"executed"<<endl;
	for(LL i=2;i<=n;i++){
		for(LL j=i;j<=n;j++){
			ans.f = INT_MIN;ans.s = INT_MAX;
			query(j-1,i-1,0,n-1,0);
			val2[i] = (val2[i]%M + (ans.s)%M)%M;
		}
	} 
	for(int i=2;i<=n;i++){cout<<val2[i]<<" ";}
	cout<<endl;
	//cout<<"executed"<<endl;
	LL res=0;
	for(LL i=1;i<n;i++){
		res = (res%M + ((val1[i])*(val2[i+1]))%M)%M;
	}
	cout<<res<<endl;
}
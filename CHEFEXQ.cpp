#include<bits/stdc++.h>
using namespace std;

int n,q;
int arr[100009],prefix[100009];
int xor_arr[500];
unordered_map<int,int> freq[500];
int net_size;
int gstart[500],gend[500],gid[100009];

void build_sqrt_decomp_array(){
	int size=1;
	while(size*size < n){size++;}

	net_size=0;
	for(int i=0;i<n;i+=size){
		gstart[net_size]=i;
		gend[net_size]=i+size-1;
		net_size++;
	}
	gend[net_size-1] = n-1;
	for(int i=0;i<net_size;i++){
		xor_arr[i]=0;
		for(int j=gstart[i];j<=gend[i];j++){
			freq[i][prefix[j]]++;
			gid[j]=i;
		}
	}
}

void process_queries(){
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		b--;

		if(a==1){
			int y = arr[b]^c;
			arr[b]=c;

			for(int i=b;i<=gend[gid[b]];i++){
				auto it = freq[gid[b]].find(prefix[i]);
				--it->second;
				if(it->second == 0){freq[gid[b]].erase(it);}
				prefix[i]=prefix[i]^y;
				freq[gid[b]][prefix[i]]++;
			}
			for(int i=gid[b]+1;i<net_size;i++){
				xor_arr[i]^=y;
			}
		}else{
			int ans=0;
			for(int i=0;i<gid[b];i++){
				auto it = freq[i].find(c^xor_arr[i]);
				if(it != freq[i].end()){ans += it->second;}
			}
			for(int i=gstart[gid[b]];i<=b;i++){
				if((prefix[i]^xor_arr[gid[b]]) == c){ans++;}
			}
			printf("%d\n",ans);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	scanf("%d %d", &n, &q);

	for(int i=0;i<n;i++){cin>>arr[i];}
	prefix[0] = arr[0];
	for(int i=1;i<n;i++){prefix[i] = prefix[i-1]^arr[i];}

	build_sqrt_decomp_array();
	process_queries();
	return 0;
}
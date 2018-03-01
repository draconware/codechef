#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL inf = (LL)1e18;

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
		LL arr[3],a,b,c;
		cin>>arr[0]>>arr[1]>>arr[2]>>a>>b>>c;

		sort(arr,arr+3);

		LL cost[6];
		for(int i=0;i<6;i++){cost[i]=inf;}

		cost[0] = a*(arr[0]+arr[1]+arr[2]);
		if(arr[0]+arr[1] < arr[2]){
			cost[1] = (arr[0]+arr[1])*b + (arr[2]-arr[1]-arr[0])*a;
 		}else{
 			cost[1] = ((arr[2]+arr[1]+arr[0])/2)*b + ((arr[2]+arr[1]+arr[0])%2)*a;
 		}

 		cost[2] = c*arr[0] + (arr[2]+arr[1]-2*arr[0])*a;
 		cost[3] = c*arr[0] + (arr[1]-arr[0])*b + (arr[2]-arr[1])*a;

 		for(LL i=arr[2]-arr[1];i<min(arr[2]-arr[1]+2000,arr[0]+1);i++){
 			LL x1 = i,y1 = arr[1]-arr[0]+i,z1 = arr[2]-arr[0]+i;
 			cost[5] = c*(arr[0]-i);
 			if(x1+y1 < z1){
 				cost[5]+=((x1+y1)*b + (z1-x1-y1)*a);
 			}else{
 				cost[5]+=(((x1+y1+z1)/2)*b + ((x1+y1+z1)%2)*a);
 			}
 			cost[3] = min(cost[3],cost[5]);
 		}

 		for(LL i=1;i<min((LL)1000,arr[0]+1);i++){
 			LL x1 = arr[0]-i,y1 = arr[1]-i,z1 = arr[2]-i;
 			cost[5] = c*i;

 			if(x1+y1 < z1){
 				cost[5]+=((x1+y1)*b + (z1-x1-y1)*a);
 			}else{
 				cost[5]+=(((x1+y1+z1)/2)*b + ((x1+y1+z1)%2)*a);
 			}
 			cost[4] = min(cost[4],cost[5]); 
 		}
 		sort(cost,cost+6);
 		cout<<cost[0]<<endl;
	}
	return 0;
}
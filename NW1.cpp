#include<bits/stdc++.h>
using namespace std;

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
		int w;
		cin>>w;

		string s;
		cin>>s;

		int x=1;
		int arr[7];
		memset(arr,0,sizeof(arr));

		while(x+7<=w){
			for(int i=0;i<7;i++){arr[i]++;}
			x+=7;
		}

		int y=0;
		if(s=="mon"){y=0;}
		else if(s=="tues"){y=1;}
		else if(s=="wed"){y=2;}
		else if(s=="thurs"){y=3;}
		else if(s=="fri"){y=4;}
		else if(s=="sat"){y=5;}
		else if(s=="sun"){y=6;}

		for(int i=x;i<=w;i++){
			arr[y]++;
			y = (y+1)%7;
		}
		for(int i=0;i<7;i++){cout<<arr[i]<<" ";}cout<<endl;
	}
	return 0;
}
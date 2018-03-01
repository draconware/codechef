#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > twice;
vector<int> ones;
vector<int> twice_arr[100009];

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
		twice.clear();ones.clear();
		for(int i=0;i<100009;i++){twice_arr[i].clear();}
		int n;
		cin>>n;

		int arr[n],b[n];

		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int cnt[100009];
		memset(cnt,0,sizeof(cnt));

		for(int i=0;i<n;i++){cnt[arr[i]]++;}

		int x=0,y=0;
		for(int i=0;i<n;i++){
			if(cnt[arr[i]]==2){x++;twice_arr[arr[i]].push_back(i);}
			else{y++;ones.push_back(i);}
		}
		x/=2;

		for(int i=0;i<n;i++){
			if(cnt[arr[i]]==2){twice.push_back(make_pair(twice_arr[arr[i]][0],twice_arr[arr[i]][1]));}
		}

		int m;
		if(x>1 && y>1){
			cout<<n<<endl;
			for(int i=1;i<x;i++){
				b[twice[i-1].first] = arr[twice[i].first];
				b[twice[i-1].second] = arr[twice[i].second];
			}
			b[twice[x-1].first] = b[twice[0].first];
			b[twice[x-1].second] = b[twice[0].second];

			for(int i=1;i<y;i++){
				b[ones[i-1]] = arr[ones[i]];
			}
			b[ones[y-1]] = arr[ones[0]];
		}else if(x==0){
			if(y==1){
				cout<<n-1<<endl;
				b[ones[0]] = arr[ones[0]];
			}else{
				cout<<n<<endl;
				for(int i=1;i<y;i++){
					b[ones[i-1]] = arr[ones[i]];
				}
				b[ones[y-1]] = arr[ones[0]];
			}
		}else if(y==0){
			if(x==1){
				cout<<n-2<<endl;
				b[twice[0].first] = arr[twice[0].first];
				b[twice[0].second] = arr[twice[0].second];
			}else{
				cout<<n<<endl;
				for(int i=1;i<x;i++){
					b[twice[i-1].first] = arr[twice[i].first];
					b[twice[i-1].second] = arr[twice[i].second];
				}
				b[twice[x-1].first] = b[twice[0].first];
				b[twice[x-1].second] = b[twice[0].second];
			}
		}else if(x==1 && y==1){
			cout<<n-1<<endl;
			b[twice[0].first] = arr[ones[0]];
			b[twice[0].second] = arr[twice[0].second];
			b[ones[0]] = arr[twice[0].first];
		}else if(x>1 && y==1){
			if(x==3){
				cout<<n-1<<endl;
				b[twice[0].first] = arr[twice[1].first];
				b[twice[0].second] = arr[twice[1].second];
				b[twice[1].first] = arr[twice[0].first];
				b[twice[1].second] = arr[twice[0].second];
				b[twice[2].first] = arr[ones[0]];
				b[ones[0]] = b[twice[2].first];
				b[twice[2].second] = arr[twice[2].second];
			}else{
				cout<<n<<endl;
				b[twice[0].first] = arr[twice[1].first];
				b[twice[0].second] = arr[twice[1].second];
				b[twice[1].first] = arr[ones[0]];
				b[twice[1].second] = arr[twice[0].first];
				b[ones[0]] = arr[twice[0].second];

				for(int i=3;i<x;i++){
					b[twice[i-1].first] = arr[twice[i].first];
					b[twice[i-1].second] = arr[twice[i].second];
				}
				b[twice[x-1].first] = b[twice[0].first];
				b[twice[x-1].second] = b[twice[0].second];
			}
		}else if(y>1 && x==1){
			if(y==3){
				cout<<n-1<<endl;
				b[twice[0].first] = arr[ones[0]];
				b[twice[0].second] = arr[ones[1]];
				b[ones[0]] = arr[twice[0].first];
				b[ones[1]] = arr[twice[1].second];
				b[ones[2]] = arr[ones[2]];
			}else{
				cout<<n<<endl;
				b[twice[0].first] = arr[ones[0]];
				b[twice[0].second] = arr[ones[1]];
				b[ones[0]] = arr[twice[0].first];
				b[ones[1]] = arr[twice[1].second];

				for(int i=3;i<y;i++){
					b[ones[i-1]] = arr[ones[i]];
				}
				b[ones[y-1]] = arr[ones[2]];
			}
		}
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}
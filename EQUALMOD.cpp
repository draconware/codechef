#include<bits/stdc++.h>
using namespace std;

int a[100009],b[100009],mod[100009];
vector<pair<int,int> > v;
vector<pair<int,int> > tra; 
int count=0;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		for(int i=0;i<n;i++){cin>>a[i];}
		for(int i=0;i<n;i++){cin>>b[i];v.push_back(make_pair(b[i],i));}

		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			a[i] = a[v[i].second];
			b[i] = v[i].first;
			mod[i] = (a[i]%b[i]);
		}
		int l=0,r=0,k=0;
		for(int i=1;i<n;i++){
			if(mod[i] >= b[0]){
				r+=(b[i]-mod[i]+1);
				mod[i]=0;
				count++;
			}else{
				tra.push_back(mod[i]);
			}
		}
	}
}
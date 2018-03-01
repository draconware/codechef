#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int t;
	cin>>t;

	while(t--){
		string s1,s2;
		cin>>s1>>s2;

		int arr1[26],arr2[26],n=s1.length(),mark1[26],mark2[26];

		memset(arr1,-1,sizeof(arr1));
		memset(arr2,-1,sizeof(arr2));
		memset(mark1,0,sizeof(mark1));
		memset(mark2,0,sizeof(mark2));
		bool flag=true;
		
		for(int i=0;i<n;i++){
			mark1[s1[i]-'a']=true;mark2[s2[i]-'a']=true;
			
			if(arr1[s1[i]-'a']==-1){
				if(arr2[s2[i]-'a']==-1){
					arr1[s1[i]-'a']=s2[i]-'a';
					arr2[s2[i]-'a']=s1[i]-'a';
				}else{
					flag=false;break;
				}
			}else if(arr2[s2[i]-'a']==-1){
				if(arr1[s1[i]-'a']==-1){
					arr1[s1[i]-'a']=s2[i]-'a';
					arr2[s2[i]-'a']=s1[i]-'a';
				}else{
					flag=false;break;
				}
			}else{
				if(arr1[s1[i]-'a']!=s2[i]-'a' || arr2[s2[i]-'a']!=s1[i]-'a'){
					flag=false;break;
				}
			}
		}
		if(flag){
			int q1=0,q2=0;
			for(int i=0;i<26;i++){
				if(!mark1[i]){q1++;}
				if(!mark2[i]){q2++;}
			}
			if(q1==0 && q2==0){
				if(s1 == s2){cout<<"YES"<<endl;}
				else{cout<<"NO"<<endl;}
			}else{
				cout<<"YES"<<endl;
			}
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
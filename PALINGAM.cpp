#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		string s,t;
		cin>>s>>t;
		int flag=2;

		int marks[30],markt[30];
		memset(marks,0,sizeof(marks));
		memset(markt,0,sizeof(markt));
		for(int i=0;i<s.length();i++){
			marks[s[i]-'a']++;
		}
		for(int i=0;i<t.length();i++){
			markt[t[i]-'a']++;
		}

		for(int i=0;i<26;i++){
			if(marks[i]>1 && markt[i]==0){
				flag=1;break;
			}
		}
		bool counter=true,counter2=false;
		for(int i=0;i<t.length();i++){
			if(marks[t[i]-'a'] == 0){
				counter=false;break;
			}
		}
		for(int i=0;i<s.length();i++){
			if(markt[s[i]-'a']==0){
				counter2=true;break;
			}
		}
		if(counter && counter2){
			flag=1;
		}
		if(flag==1){
			cout<<"A"<<endl;
		}else{
			cout<<"B"<<endl;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>n>>m;

		int arr[n][m];
		vector<LL> minsalary(n,0),offeredsalary(m,0),maxjoboffers(m,0);
		for(int i=0;i<n;i++){
			cin>>minsalary[i];
		}
		for(int i=0;i<m;i++){
			cin>>offeredsalary[i]>>maxjoboffers[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[n][m];
			}
		}
		LL res_students=0,res_salary,res_company=0;
		bool company[m+1];
		memset(company,0,sizeof(company));
		for(int i=0;i<n;i++){
			LL x = minsalary[i];
			LL pick=-1;
			LL idx=-1;
			for(int j=0;j<m;j++){
				if(arr[i][j]==1 && maxjoboffers[j]>0){
					 if(x <= offeredsalary[j]){
					 	if(pick < offeredsalary[j]){
					 		pick = offeredsalary[j];
					 		idx = j;
					 	}
					 }
				}
			}
			if(idx != -1){
				res_students++;
				res_salary+=offeredsalary[idx];
				maxjoboffers[idx]--;
			}else{
				res_company++;
			}
		}
		cout<<res_students<<" "<<res_salary<<" "<<res_students<<endl;
	}
	return 0;
}
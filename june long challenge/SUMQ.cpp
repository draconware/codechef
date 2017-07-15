#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define M 1000000007

int main(){
    int t;
    cin>>t;

    while(t--){
        LL p,q,r,ans=0;
        cin>>p>>q>>r;

        vector<LL> sum_x(p),sum_y(q),sum_z(r),x(p),y(q),z(r);
        LL temp=0;
        for(LL i=0;i<p;i++){cin>>x[i];sum_x[i]=(temp+x[i])%M;temp = sum_x[i];}temp=0;
        for(LL i=0;i<q;i++){cin>>y[i];sum_y[i]=(temp+y[i])%M;temp = sum_y[i];}temp=0;
        for(LL i=0;i<r;i++){cin>>z[i];sum_z[i]=(temp+z[i])%M;temp = sum_z[i];}temp=0;

        sort(x.begin(),x.end());sort(z.begin(),z.end());
        //for(LL i=0;i<p;i++){cout<<sum_x[i]<<" ";}cout<<endl;
        //for(LL i=0;i<q;i++){cout<<sum_y[i]<<" ";}cout<<endl;
        //for(LL i=0;i<r;i++){cout<<sum_z[i]<<" ";}cout<<endl;
        vector<LL>::iterator it;
        LL i,j,k;
        for(j=0;j<q;j++){
            it = upper_bound(x.begin(),x.end(),y[j]);
            if(it == x.end()){i = p;}
            else{i = it-x.begin();}

            it = upper_bound(z.begin(),z.end(),y[j]);
            if(it == z.end()){k = r;}
            else{k = it-z.begin();}
            //cout<<i<<" "<<j<<" "<<k<<endl;
            if(i==0 || k==0){continue;}
            ans += (sum_x[i-1] * sum_z[k-1])%M + ( y[j] * ((k*sum_x[i-1])%M+(i*sum_z[k-1])%M)%M )%M + ((i*k)%M * (y[j]*y[j])%M)%M;
        }
        cout<<ans<<endl;
    }
    return 0;
}

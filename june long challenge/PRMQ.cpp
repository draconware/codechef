#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000005

bool mark[MAX];
vector<int> prime[MAX];
vector<int> v[MAX];
vector<int> arr;

void pre(){
    for(int i=0;i<MAX;i++){mark[i]=true;}
    for(int i=2;i*i<MAX;i++){
        if(mark[i]){
            for(int j=(i*i);j<MAX;j+=i){
                mark[j]=false;
            }
        }
    }
    pair<int,int> p;
    for(int i=2;i<MAX;i++){
        if(!mark[i]){
            int k=i;
            for(int j=2;(j*j)<=k;j++){
                if((mark[i]) && !(k%j)){
                    int e=0;
                    while(!(k%j)){
                        e++;
                        k/=j;
                    }
                    prime[i].push_back(e);
                    v[i].push_back(j);
                }
            }
            if(k!=1){
                prime[i].push_back(1);
                v[i].push_back(i);
            }
        }else{
            prime[i].push_back(1);
            v[i].push_back(i);
        }
    }
}

int f(int l,int r,int x,int y){
    int res=0;
    for(int i=x;i<=y;i++){
        if(mark[i]){
            for(int j=l;j<=r;j++){
                int a = arr[j];
                if(a == i){
                    res++;
                }else if(a > i){
                    int k = lower_bound(v[a].begin(),v[a].end(),i)-v[a].begin();
                    if((k != v[a].size())&&(v[a][k] == i)){
                        res += prime[a][k];
                    }
                }
            }
        }
    }
    return res;
}

int main(){
    pre();
    int n,q,a;
    scanf("%d %d", &n, &q);

    for(int i=0;i<n;i++){
        scanf("%d", &a);
        arr.push_back(a);
    }
    int l,r,x,y;
    while(q--){
        scanf("%d %d %d %d", &l, &r, &x, &y);
        cout<<f(l-1,r-1,x,y)<<endl;
    }
    return 0;
}

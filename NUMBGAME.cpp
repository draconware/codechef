#include<bits/stdc++.h>
using namespace std;
 
#define N  1000005
 
char s[N];
int M;
int flag[1005], cnt[1005], n, v[1005];
 
vector<int> adj[1005];
int r[N];
 
struct Node {
    int start;
    int cur;
    int count;
    Node(int s = 0, int c = 0, int cc = 0) :
            start(s), cur(c), count(cc) {}
};
 
void search(int u) {
    int i;
    for ( i = 0 ; i < adj[u].size() ; i ++ ) {
        int v = adj[u][i];
        if ( flag[v] == 1 ) continue;
        flag[v] = 1;
        search(v);
    }
}
 
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("my.out", "w", stdout);
    int T, t, i, j, k, len;
    scanf("%d", &T);
    for ( t = 1 ; t <= T ; t ++ ) {
        scanf("%s%d", s, &M);
        len = strlen(s);
        memset(flag, 0, sizeof(flag));
        memset(cnt, 0, sizeof(cnt));
 
        for ( i = 0 ; i < M ; i ++ ) adj[i].clear();
 
        r[0] = 1;
        int tr = 0, sr = 1;
        for ( i = 0 ; i < len - 1 ; i ++ ) sr = (sr*10)%M;
        for ( i = 0 ; i < len ; i ++ ) {
            r[i+1] = (r[i]*10)%M;
            tr = (tr*10 + s[i] - '0')%M;
        }
 
        int tmp, pr = 0, prv = 0;
        for ( i = 0 ; i < len ; i ++ ) {
            pr = (pr*10 + s[i] - '0')%M;
            tmp = (tr + (prv - pr + M)*r[len - i - 1])%M;
            cnt[tmp]++;
            prv = pr;
        }
 
        n = 0;
        for ( i = 0 ; i < M ; i ++ ) {
            if ( cnt[i] ) {
                v[n++] = i;
            }
        }
 
//        cout << sr << endl;
//        for ( i = 0 ; i < n ; i ++ ) cout << v[i] << ' '; cout << endl;
//        for ( i = 0 ; i < M ; i ++ ) cout << cnt[i] << ' '; cout << endl;
//
        for ( i = 0 ; i < M ; i ++ ) {
            for ( j = 0 ; j < n ; j ++ ) {
                adj[(i*sr + v[j])%M].push_back(i);
            }
        }
 
        flag[0] = 1;
        search(0);
 
        int res = 0;
 
        for ( i = 0 ; i < M ; i ++ ) {
            if ( cnt[i] == 0 ) continue;
            if ( flag[i] ) res += cnt[i];
        }
 
        printf("%d\n", res);
    }
    return 0;
}
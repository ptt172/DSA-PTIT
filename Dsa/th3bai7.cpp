#include <bits/stdc++.h>
using namespace std;
int n , m , c ;
vector <int> a [100005];
int num [100005] , nho [100005] , parent[100005];
bool vs [100005] , dung [100005];
int res[100005];
void dfs (int u){
    vs[u] = true;
    num[u] = nho [u] = ++ c ;
    int m = 0;
    for (int v : a[u]){
        if (!vs[v]){
            parent [v] = u ;
            m ++;
            dfs (v);
            nho[u] = min (nho [u] , nho [v]);
            if (parent [u] == -1){
                res [u] = m -1 ;
            }
            else {
                if (nho [v] >= num [u]){
                    res [u] ++;
                }
            }
        }
        else if (v != parent [u]){
            nho [u] = min (nho[u],num [v]);
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 1;  i <= n ;i++){
        a[i].clear ();
        vs[i]  = false;
        parent [i] = -1;
        res [i] = 0;
    }
    for (int i = 0 ; i<  m ; i++){
        int u , v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    c= 0;
    for (int i =1 ; i<= n ;i++){
        if (!vs[i]) {
            dfs (i);
        }
    }
    int best = 0 , ans = 0;
    for (int i = 1; i<= n ;i++){
        int cmp = res[i] + 1;
        if (res[i] > best ){
            best = res[i];
            ans = i;
        }
    }
    if (best <= 1) cout << 0 << endl;
    else cout << ans << endl;
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n , m , c ;
vector <int> a [105];
int num [105] , nho [105];
bool vs [105] , dung [105];
int res[105];
void dfs (int u , int parent){
    vs[u] = true;
    num[u] = nho [u] = ++ c ;
    int m = 0;
    for (int v : a[u]){
        if (v == parent) continue;
        if (!vs[v]){
            dfs (v , u);
            m ++ ;
            nho[u] = min (nho [u] , nho [v]);
            if (parent != -1 && nho [v] >=  num [u]){
                res [u]++  ;
            }
        }
            else {
                nho [u] = min (nho[u],num [v]);
            }
        }
        if (parent == -1){
            res[u] = m;
        }
        else {
            res[u] ++;
        }
}
int main(){
    int t;
    cin >> t;
    while (t--){
    cin >> n >> m;
    for (int i = 1;  i <= n ;i++){
        a[i].clear ();
        vs[i]  = false;
        res [i] = nho [i] = num [i] = 0;
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
            dfs (i , -1);
        }
    }
    int best = 1 , ans = 0;
    for (int i = 1; i<= n ;i++){
        if (res[i] > best ){
            best = res[i];
            ans = i;
        }
    }
    if (best == 1) cout << 0 << endl;
    else cout << ans << endl;
}

    return 0;
}
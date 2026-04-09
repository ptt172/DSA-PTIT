#include <bits/stdc++.h>
using namespace std;

int n , st , en , cnt = 0;
int a[105][105] = {} , c[105] = {};
bool vs[105] = {};
void dfs1 (int u , int d){
    if (d > 2) return ;
    if (d == 2 && u == en){
        cnt ++;
        return ;
    }
    vs[u] = true;
    for (int i = 1 ;  i <= n ; i++){
        if (!vs[i] && a[u][i]){
            dfs1 (i , d + 1);
        }
    }
    vs[u]  = false;
}
bool ok = false;
void dfs2 (int u){
    if (u == en){
        ok = true;
        return ;
    }
    vs[u]  = true;
    for (int i = 1; i <= n ; i++){
        if (!vs[i] && a[u][i]){
            c[i] = u;
            dfs2 (i);
            if (ok) return ;
        }
    }
    vs[u] = false;
}
bool ok = false ;
vector <int> res;
int main (){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t ;
    cin >> t;
    cin >> n >> st >> en;
    for (int i = 1;  i <= n ; i++){
        for (int j = 1;  j <= n ; j++){
            cin >> a[i][j];
        }
    }
    if ( t == 1  ){
        dfs1 (st ,0);
        cout << cnt << endl;
    }
    else {
        dfs2 (st);
        if (!ok) cout << "0" << endl;
        else {
            vector <int> res;
            int u = en ;
            while (u != st){
                res.push_back (u);
                u = c[u];
            }
            res.push_back (st);
            for (int i = res.size () - 1 ; i >= 0 ; i--) cout << res[i] << " ";
        }
    }
}
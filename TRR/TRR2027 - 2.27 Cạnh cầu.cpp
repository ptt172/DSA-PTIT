#include <bits/stdc++.h>
using namespace std;

int n , e = 0 , a[105][105] = {};
bool vs[105] = {};
set <int> ke[105];
vector <pair <int , int>> dsc;
void dfs (int u){
    vs[u] = true;
    for (int v : ke[u]){
        if (!vs[v]) dfs (v);
    }
}
int tptl (){
    int cnt = 0;
    for (int i = 1;  i <= n ; i++){
        if (!vs[i]){
            dfs (i);
            cnt ++ ;
        }
    }
    return cnt;
}
int main (){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1;  i <= n ; i++){
        for (int j = 1;  j <= n ; j++){
            cin >> a[i][j];
            if (a[i][j] && j > i ) {
                ke[i].insert(j);
                ke[j].insert(i);
                e ++ ;
                dsc.push_back({i , j});
            }
        }
    }
    int cnt = tptl ();
    vector <pair <int , int>> res;
    for (int i = 0 ; i < e ; i++){
        memset (vs , 0 , sizeof (vs));
        auto [x , y] = dsc[i];
        ke[x].erase (y);
        ke[y].erase (x);
        if (cnt < tptl ()) res.push_back ({x , y});
        ke[x].insert (y);
        ke[y].insert (x);
    }
    cout << res.size () << endl;
    for (auto [x , y] : res) cout << x << " " << y << endl;
}
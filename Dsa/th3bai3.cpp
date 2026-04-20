#include <bits/stdc++.h>
using namespace std;
int n , m;
vector <vector <int>> a;
vector <bool> vs;
int dfs (int u){
    vs [u] = true;
    int cnt = 1;
    for (int v : a[u]){
        if (!vs[v]){
            cnt += dfs (v);
        }
    }
    return cnt ;
}
int main(){
    cin >> n >> m;
    a.resize (n + 1);
    vs.assign (n + 1 , false );
    for (int i = 0 ;i < m ; i++){
        int u , v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back(u);
    }
    int sz = dfs (1);
    int nhieu = 0;
    for (int i = 1; i<= n ;i++){
        if (!vs[i]){
            int size = dfs (i);
            nhieu = max (nhieu  ,size);
        }
    }
    cout << sz + nhieu << endl;

    return 0;
}
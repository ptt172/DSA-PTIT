#include <bits/stdc++.h>
using namespace std;

int n , m;
vector <vector <int>> a;
vector <bool> vs;

bool dfs (int u){
    vs[u] = true;
    for (int v : a[u]){
        if (vs[v]) return true;
        if (dfs(v)) return true;
    }
    vs[u] = false;
    return false;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m ;
        a.assign (n + 1 , {});
        vs.assign (n + 1 , false);
        for (int i = 1; i<=  m; i ++){
            int x , y;
            cin >> x >> y;
            a[x].push_back (y);
        }
        bool found = false;
        for (int i = 1; i<= n ;i++){
            if (dfs (i)){
                found = true;
                break;
            }
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
}
}
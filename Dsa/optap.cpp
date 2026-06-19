#include <bits/stdc++.h>
using namespace std;


int T ,V , E , u , v;
vector <int> a[1005];
bool vs[1005];

bool dfs (int u , int parent){
    vs[u] = true;;
    for (int v : a[u]){
        if (!vs[v]){
            if (dfs (v , u)){
                return true;
            }
        }
        else if (v != parent) return true;
    }
    return false;
}

int main (){
    cin >> T;
    while (T--){
        cin >> V >> E;
        for (int i = 1; i<= V;  i++) {
            a[i].clear ();
            vs[i] = false;
        }
        for (int i = 0 ; i < E ; i++){
            cin >> u >> v;
            a[u].push_back (v);
            a[v].push_back(u);
        }
        bool ok = false;
        for (int i = 1; i<= V ; i++){
            if (!vs[i]){
                if (dfs (i , -1)){
                    ok = true;
                }
            }
        }
        if (ok) cout << "YES\n" ;
        else cout << "NO\n" ;
    }
}
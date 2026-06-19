#include <bits/stdc++.h>
using namespace std;


vector<int> a[1005];
int vs[1005];
bool dfs(int u){
    vs[u] = 1; 
    for(int v : a[u]){
        if(vs[v] == 1)
            return true; 
        if(vs[v] == 0){
            if(dfs(v))
                return true;
        }

    }
    vs[u] = 2; 
    return false;
}

int main(){
    int T, V, E, u, v;
    cin >> T;
    while(T--){
        cin >> V >> E;
        for(int i = 1; i <= V; i++){
            a[i].clear();
            vs[i] = 0;
        }
        for(int i = 0; i < E; i++){
            cin >> u >> v;
         a[u].push_back(v);
        }
        bool ok = false;
        for(int i = 1; i <= V; i++){
            if(!vs[i]){
                if(dfs(i)){
                    ok = true;
                    break;
                }
            }
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
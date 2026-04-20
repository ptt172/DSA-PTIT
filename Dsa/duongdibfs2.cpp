#include <bits/stdc++.h>
using namespace std;

int n , m , s , parent[1005];
vector <int> a[1005];
bool vs[1005];

void bfs (){
    queue <int> q;
    q.push (s);
    vs[s] = true;
    parent[s] = -1;
    while (!q.empty()){
        int u = q.front (); q.pop ();
        for (int v : a[u]){
            if (!vs[v]){
                vs[v] = true;
                parent[v] = u;
                q.push (v);
            }
        }
    }
}
void in (int v){
    if (!vs[v]){
        cout << "No path";
        return;
    }
    vector <int> path;
    while (v != -1){
        path.push_back (v);
        v = parent[v];
    }
    reverse (path.begin () , path.end ());
    for (int x : path) cout << x << " ";
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++){
            a[i].clear();
            vs[i] = false;
            parent[i] = 0;
        }
        for (int i = 0 ; i < m; i++){
            int u , v;
            cin >> u >> v;
            a[u].push_back (v);
            a[v].push_back (u);
        }
        bfs();
        for (int i = 1 ; i <= n ; i++){
            if (i == s) continue;
            in(i);
            cout << endl;
        }
    }
    return 0;
}
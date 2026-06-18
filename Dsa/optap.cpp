#include <bits/stdc++.h>
using namespace std;

vector <int> a[1005];
bool vs[1005];
int parent[1005];

void bfs (int s){
    queue <int> q;
    q.push (s);
    vs[s] = true;
    while (!q.empty ()){
        int u = q.front();
        q.pop ();
        for (int v : a[u]){
            if (!vs[v]){
                vs[v] = true;
                parent[v] = u;
                q.push (v);
            }
        }
    }
}
int main (){
    int c;
    cin >> c;
    while (c--){
        int n , m , s , t;
        cin >> n >> m >> s >> t;
        for (int i = 1; i<= n ;i++){
            a[i].clear ();
            vs[i] = false;
            parent[i] = 0;
        }
        for (int i = 0 ; i< m ; i++){
            int u , v;
            cin >> u >> v;
            a[u].push_back (v);
        }
        bfs (s);
        if (!vs[t]){
            cout << -1 << endl;
            continue;
        }
        vector <int> path;
         int x = t;
        while (x != s){
            path.push_back (x);
            x = parent[x];
        }
        path.push_back (s);
        reverse (path.begin () , path.end ());
        for (int v : path) cout << v << " ";
        cout << endl;
        
    }
}
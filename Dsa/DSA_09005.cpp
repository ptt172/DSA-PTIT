#include <bits/stdc++.h>
using namespace std;

int v , e , u , x , y;
vector <vector <int>> g ;
vector <bool> vs;

void bfs (int u){
    queue <int> q;
    q.push (u);
    while (!q.empty ()){
        int u = q.front () ; q.pop();
        if (!vs[u]){
            cout << u << " ";
            vs[u] = true; 
        }
        for (int j : g[u]){
            if (!vs[j]){
                q.push(j);
            }
        }
    }

}
int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> v >> e >> u;
        g.assign (v + 1 , vector <int>());
        vs.assign (v + 1, 0);
        while (e--){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bfs (u);
        cout << endl;
    }
}
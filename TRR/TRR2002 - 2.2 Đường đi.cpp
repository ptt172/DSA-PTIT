#include <bits/stdc++.h>
using namespace std;

int n , st , en , cnt = 0;
int a[105][105] = {} ,path [105][105] = {};
bool vs [105] = {};
void dfs (int u , int d){
    if (d > 2) return;
    if (d == 2 && u == en){
        cnt ++ ;
        return;
    } 
    vs[u] = true;
    for (int v = 1; v <= n ; v ++){
        if (!vs[v] && a[u][v]){
            dfs (v , d + 1);
        }
    }
    vs[u] = false;
}
bool ok = false;
vector <int> res;
void bfs  (){
    queue <pair <int, vector <int>>> q;
    q.push ({st , {st}});
    while (!q.empty ()){
        pair <int,vector <int>> top = q.front();
        q.pop ();
        int u  = top.first;
        vector <int> c = top.second;
        if ( u == en){
            res = c;
            return ;
        }
        vs[u] = true;
        for (int v = 1; v <= n ; v++){
            if (!vs[v] && a[u][v]){
                c.push_back(v);
                q.push ({v , c});
                c.pop_back();
            }
        }
    }
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n >> st >> en;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (t == 1){
        dfs (st, 0);
        cout << cnt << endl;
    }
    else {
        bfs ();
        if (res.size() == 0) cout << "0" << endl;
        else for (int x : res) cout << x << " ";
    }
    

    return 0;
}
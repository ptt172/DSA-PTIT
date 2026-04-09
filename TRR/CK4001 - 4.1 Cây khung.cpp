#include <bits/stdc++.h>
using namespace std;

int n , st , a[105][105] = {};
bool vs [105] = {};
set<int> ke[105];
vector <vector <int>> res;

void dfs (int u){
    vs[u] = true;
    for (int v : ke[u]){
        if (!vs[v]){
            res.push_back({u , v});
            dfs (v);
        }
    }
}
void bfs (){
    for (auto &x : vs) x = false;
    queue <int> q;
    q.push(st);
    vs[st] = true;
    while (!q.empty()){
        int u = q.front () ;
        q.pop();
        for (int v : ke[u]) {
            if (!vs[v]){
                res.push_back({u , v});
                vs[v] = true;
                q.push (v);
            }
        }
    }

}
int main (){
    int t ;
    cin >> t >> n >> st;
    for (int i = 1;  i <= n ;i++){
        for (int j =1 ; j <= n ; j++){
            cin >> a[i][j];
            if (a[i][j]) ke[i].insert (j);
        }
    }
    if (t == 1) dfs (st);
    else bfs ();
    if (res.size () == n -1) {
        cout << res.size () << endl;
        for (vector <int> v : res) cout << v[0] << "  " << v[1] << endl;
    }
    else cout <<"0" << endl;
}
#include <bits/stdc++.h>

using namespace std;
int n ;
int a[105][105] = {};
bool vs [105] = {};

set <int> c;
vector <set <int>> res;
void dfs (int u){
    c.insert (u);
    vs[u] = true;
    for (int i = 1 ; i <= n ;i++){
        if (!vs[i] && a[u][i]){
            dfs (i);
        }
    }
}
int main (){
    cin >> n;
    for (int i =1;  i <= n ; i++){
        for (int j = 1 ;j <= n ; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1 ; i<= n ; i++){
        if (vs[i]) continue;
        dfs (i);
        res.push_back (c);
        c.clear ();
    }
    cout << res.size () << endl;
    for (auto x : res) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }

    
}
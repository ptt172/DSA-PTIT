#include <bits/stdc++.h>
using namespace std;

int n , s , t;
vector <pair <int,int>> dsc;
vector <int> c(105,-1);
int a[105][105] = {};
void bellman_ford () {
    vector <int> dp (105, INT_MAX);
    dp[s] = 0;
    for (int i = 1;  i < n ; i++){
        for (auto [u , v] : dsc){
            if (dp[u] != INT_MAX && dp[v] > dp[u] + a[u][v]){
                dp [v] = dp[u] + a[u][v];
                c[v] = u;
            }
        }
    }
    for (auto [u,v] : dsc) {
        if (dp[u] != INT_MAX && dp[v] > dp[u] + a[u][v]){
            cout << "-1\n";
            return ;
        }
    }
    if (dp[t] == INT_MAX){
        cout <<0 << endl;
        return ;
    }
    else cout <<dp[t] << endl;
    vector <int> res;
    while (t != -1){
        res.push_back (t);
        t = c[t];
    }
    reverse (res.begin (),res.end ());
    for (int x : res) cout << x << " ";
}
int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] <= 50) dsc.push_back({i, j});
        }
    }
    bellman_ford();
    
    return 0;
}
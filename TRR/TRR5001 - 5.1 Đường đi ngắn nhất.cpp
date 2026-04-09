#include <bits/stdc++.h>
using namespace std;

int  n , s , t;
vector <int> dske [105];
vector <int> c (105 , -1);
int a[105][105] ={};
 
void dijkstra (){
    queue <pair <int,int>> q;
    q.push ({s , 0});
    vector <int> dp (105 , INT_MAX);
    dp[s] = 0;
    while (!q.empty ()){
        auto [u,w] = q.front();
        q.pop();
        if (w > dp[u]) continue;
        for (int v : dske [u]){
            if (dp[v] > dp[u] + a[u][v]){
                dp[v] = dp[u] + a[u][v];
                c[v]  = u;
                q.push ({v , dp[v]});
            }
        }
    }
    if (dp[t] == INT_MAX){
        cout << 0 << endl;
        return;
    }
    else cout << dp[t] << endl;
    vector <int> res;
    do{
        res.push_back (t);
        t = c[t];
    }
    while (t != -1);
    reverse (res.begin () , res.end());
    for (int x : res) cout << x << " ";
}
int main (){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1;  i <= n ; i++){
        for (int j = 1;  j<= n ; j++){
            cin >> a[i][j];
            if (a[i][j] > 0 && a[i][j] <= 50) dske[i].push_back (j);
        }
    }
    dijkstra ();
}
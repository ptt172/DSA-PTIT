#include <bits/stdc++.h>
using namespace std;    

int n , a[105][105] = {};
bool vs[105]  = {};
void bfs (int s){
    queue <int> q;
    q.push (s);
    while (!q.empty ()){
        int u  = q.front ();
        q.pop();
        vs[u] = true;
        for (int i = 1 ; i <= n ; i++){
            if (!vs[i] && a[u][i]){
                q.push (i);
            }
        }
    }
}
int tplt (){
    int cnt = 0;
    for (int i = 1;  i<= n ; i++){
        if (vs[i]) continue;
        bfs (i);
        cnt ++ ;

    }
    return cnt;
}
int main (){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1;  i <= n ; i++){
        for (int j = 1;  j <= n ; j++){
            cin >> a[i][j];
        }
    }
    int cnt = tplt ();
    vector <int> res;
    for (int i = 1;  i<= n ; i++){
        memset (vs ,  0 , sizeof (vs));
        vs[i] = true;
        if (cnt < tplt ()) res.push_back (i);
    }
    cout << res .size () << endl;
    for (auto x : res) cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int n , m;
vector <vector <int>> a;
vector <pair<int,int>> ed;
vector <bool> vs;
void dfs1 (int u){
    vs[u] = true;
    for (int x : a[u]){
        if (!vs[x]) dfs1(x);
    }
}
void dfs2 (int u , int s ,int t){
    vs[u] = true;
    for (int x : a[u]){
        if (x == s && u == t || x == t && u == s) continue;

        else if (!vs[x]) dfs2 (x , s , t);
    }
}
int main(){
    cin >> n >> m;
    a.assign(n + 1 ,{});
    ed.clear ();
    vs.assign (n + 1 , false);
    for (int i = 0 ; i<m ; i++){
        int x , y;
        cin >> x >> y;
        a[x].push_back (y);
        a[y].push_back (x);
        ed.push_back ({x , y});
    }
    int k = 0 ;
    for (int i = 1; i<= n ;i++){
        if (!vs[i]){
            k ++ ;
            dfs1 (i);
        }
    }
    int q = 0 , w = 0;
    for (int i = 1; i<= n ;i++){
        vs.assign (n + 1 , false);
        vs[i] = true;
        int cnt = 0;
        for (int j = 1; j <= n ;j++){
            if (!vs[j]){
                ++ cnt;
                dfs1 (j);
            }
        }
        if (cnt > k) q ++;
    }
    for (auto x : ed){
        vs.assign (n + 1 , false );
        int cnt= 0 ;
        for (int j = 1; j  <= n ;j++){
            if (!vs[j]){
                cnt ++;
                dfs2 (j , x.first , x.second);
            }
        }
        if (cnt > k) w ++;
    }
    cout << q << " " << w << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int v , e , u , x , y;
vector <vector <int>> g ;
vector <bool> vs;

void dfs (int u){
    stack <int> st;
    st.push (u);
    while (!st.empty ()){
        int u = st.top () ; st.pop ();
        if (!vs[u]){
            cout << u << " ";
            vs[u] = true;
        }
        for (int i = g[u].size () - 1 ; i >= 0 ; i--){
            int j = g[u][i];
            if (!vs[j]){
                st.push (j);
            }
        }
    }
}
int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> v >> e >> u;
        g.assign (v + 1 , vector <int> ()) ;
        vs.assign (v + 1 , 0);
        while (e--){
            cin >> x >> y;
            g[x].push_back (y);
            g[y].push_back (x);
        }
        dfs (u);
        cout << endl;
    }
}
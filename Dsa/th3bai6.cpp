#include <bits/stdc++.h>
using namespace std;

vector <int> a[100005] , rev [100005];
bool vs [100005];
stack <int> st;
void dfs1 (int u){
    vs[u] = true;
    for (int v : a[u]){
        if (!vs[v]){
            dfs1 (v);
        }
    }
    st.push (u);
}
void dfs2 (int u){
    vs[u] = true;
    for (int v : rev [u]){
        if (!vs[v]) dfs2 (v);
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n , m;
        cin >> n >> m;
        for (int i = 1; i <= n ;i++){
            a[i].clear ();
            rev[i].clear();
            vs[i] = false;
        }
        while (!st.empty ()){
            st.pop ();
        }
        for (int i = 0 ; i < m ; i++){
            int u , v;
            cin >> u >> v;
            a[u].push_back (v);
            rev[v].push_back (u);
        }
        for (int i = 1; i<= n ;i++){
            if (!vs[i]) dfs1 (i);
        }
        memset (vs , 0 , sizeof (vs));
        int scc = 0;
        while (!st.empty()){
            int u = st.top () ; st.pop ();
            if (!vs[u]){
                dfs2 (u);
                scc ++;
            }
        }
        cout << scc << endl;
        
    }

    return 0;
}
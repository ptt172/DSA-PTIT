#include <bits/stdc++.h>
using namespace std;

int V , E , s , t , u , v ;
vector <vector <int>> g;
vector <bool> vs;
vector <int> b;
void dfs(int s) {
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        u = st.top(); st.pop();
        vs[u] = true;
        if (u == t) return;
        for (int v : g[u]) {
            if (vs[v] == false) {
                st.push(u);
                st.push(v);
                b[v] = u;
                break;
            }
        }
    }
}

void trace() {
    if (vs[t] == false) {
        cout << -1;
        return;
    }
    stack<int> way;
    int last = t;
    while (last != -1) {
        way.push(last);
        last = b[way.top()];
    }
    while (!way.empty()) {
        cout << way.top() << " ";
        way.pop();
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> V >> E >> s >> t;
    g.clear(); g.resize(V + 1);
    vs.clear(); vs.resize(V + 1, 0);
    b.clear(); b.resize(V + 1, -1);
        while (E--){
            cin >> u >> v;
            g[u].push_back (v);
        }
        dfs (s);
        trace ();
        cout << endl;

    }
}
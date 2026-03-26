#include <bits/stdc++.h>
using namespace std;
// tham khao 
int V , E , s , t , u , v ;
vector <vector <int>> g;
vector <bool> vs;
vector <int> b;
void dfs (int s){
    stack <int> st;
    st.push (s);
    while (!st.empty ()){
        int u = st.top (); st.pop();
        vs [u] = true;
        if (u == t) return ;
        for (int j : g[u]){
            if (!vs[j]){
                st.push (j);
                vs[j] = true;
                b[j] = u;
            }
        }
    }

}

void trace() { // truy vet tu s -> t 
    if (!vs[t]) {
        cout << -1 << endl;
        return;
    }
    else{
    vector<int> path;
    int last = t; // tu dich
    while (last != -1) {
        path.push_back(last); // them dinh vao duong di
        last = b[last]; // di toi dinh cua last
    }
    reverse(path.begin(), path.end()); // dang tu t - > s nên đảo lại 
    for (int x : path) cout << x << " ";
    cout << endl;
}
}

int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> V >> E >> s >> t;
        g.assign (V + 1 , vector <int> ());
        vs.assign (V + 1 , 0);
        b.assign (V+1 , -1);
        while (E--){
            cin >> u >> v;
            g[u].push_back (v);
        }
        dfs (s);
        trace ();
        

    }
}
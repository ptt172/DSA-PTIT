#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int V , E ,u , v , lth ;
vector <vector <int>> g;
vector <bool> vs;
// Cạnh cầu là cạnh quan trọng nhất trong việc giữ đồ thị liên thông
// có thể thay bfs  = dfs

void dfs(int s) {
    stack<int> st;
    st.push(s);
    vs[s] = 1;
    
    while (!st.empty()) {
        u = st.top(); st.pop();
        for (int v : g[u]) {
            if (!vs[v]) {
                vs[v] = 1;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
}
int main (){
    int t;
    cin >> t;
    while (t--){
        lth = 0;
        cin >> V >> E ;
        g.assign(V + 10 , vector <int>());
        vs .assign (V+ 10  , 0);
        for (int i = 1 ; i<= E ;i ++){
            cin >> u >> v;
            g[u].push_back (v);
        }
        int found = 0;
        for (int i = 1; i <= V ;i ++){
            dfs(i);
            for (int j = 1 ; j <= V ; j++){
            if (!vs[j]){
                found = 1;
                break;
            }
        }
        if (!found) break;
    }
        if (!found){
        cout << "YES" << endl;}
        else cout << "NO" << endl;
}
}

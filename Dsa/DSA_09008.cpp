#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int V , E ,u , v , lth ;
vector <vector <int>> g;
vector <bool> vs;
// Cạnh cầu là cạnh quan trọng nhất trong việc giữ đồ thị liên thông
//Trong đồ thị có vòng, không có cạnh cầu, vì luôn có đường đi thay thế.

void bfs (int bd){
    queue <int> q;
    q.push(bd);
    vs[bd] = true;
    while  (!q.empty ()){
        u = q.front() ; q.pop ();
        for (int j : g[u]){
            if (!vs[j]){
                q.push (j);
                vs[j] = true;
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
            g[v].push_back (u);

        }
        for (int i = 1; i <= V ;i ++){
            if (!vs[i]){
                bfs(i);
                lth ++;
            }
        }
        cout << lth << endl;
    }
}
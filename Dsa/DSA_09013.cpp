#include <bits/stdc++.h>
using namespace std;

int V , E ,u , v , x , y , lth ;
vector <vector <int>> g;
vector <pair <int,int>> ed;
vector <bool> vs;
// Cạnh cầu là cạnh quan trọng nhất trong việc giữ đồ thị liên thông
//Trong đồ thị có vòng, không có cạnh cầu, vì luôn có đường đi thay thế.

void bfs (int bd){
    queue <int> q;
    q.push(bd);
    while  (!q.empty ()){
        u = q.front() ; q.pop ();
        vs[u] = true;
        for (int j : g[u]){
            if ((u == x && j == y) || (u == y && j == x)){
                continue;
            }
            if (!vs[j]){
                q.push (j);
            }
        } 
    }
}
void canhcau (){
    vs .assign (V+1 , 0);
    int moilth = 0;
    for (int i = 1; i <= V ; i++){
        if (!vs[i]){
            bfs(i);
            moilth ++;
        }
    }
    if (moilth > lth) {
        cout << x << " " << y << " ";
    }
}


int main (){
    int t;
    cin >> t;
    while (t--){
        lth = 0;
        x = y = -1;
        cin >> V >> E ;
        g.assign(V + 1 , vector <int>());
        ed.assign (E + 1 , pair <int,int>());
        vs .assign (V+1 , 0);
        for (int i = 1 ; i<= E ;i ++){
            cin >> u >> v;
            ed[i] = {u , v};
            g[u].push_back (v);
            g[v].push_back (u);

        }
        for (int i = 1; i <= V ;i ++){
            if (!vs[i]){
                bfs(i);
                lth ++;
            }
        }
        for (int i = 1;  i<= E ;i ++){
            x = ed[i].first;
            y = ed[i].second;
            canhcau (); 
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
int v , e , s , m, check [1005] , b [1005];
vector <int> a [1005];
void bfs (int u){
    queue <int> q;
    q.push(u);
    check [u] = 1;
    while (!q.empty()){
        int u  = q.front() ; q. pop();
        for (int i = 0 ; i < a[u].size () ; i++){
            int t = a[u][i] ;
            if (check [t] == 0) {
                check [t] = 1;
                q.push (t);
                b[t] = u;
            }
        }
    }
}
int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> v >> e >> s >> m;
        memset (a , 0 , sizeof (a));
        memset (check , 0 , sizeof (check));
        for (int i = 1; i<= e ;i++){
            int x , y;
            cin >> x >> y;
            a[x].push_back (y);
        }
        bfs (s);
        if (check [m] == 0) cout << -1 << endl;
        else {
            vector <int> res;
            int i = m; cout << s << " ";
            while (i != s) {
                res.push_back (i);
                i = b[i];
            }
            for (int i = res.size () - 1 ; i >= 0 ; i--){
                cout << res [i] << " ";
            }
            cout << endl;
        }
    }
}
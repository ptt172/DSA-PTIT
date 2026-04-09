#include <bits/stdc++.h>
using namespace std;
int cnt  , sz = 0;
vector <vector <int>> a  (105 , vector <int> (105 ,0));
void dfs (vector <set <int>> & dske , int u , vector <bool> & vs){
    vs [u] = true ;
    cnt ++;
    for (auto x : dske[u]){
        if (!vs[x]) dfs (dske , x , vs);
    }
}

int checkeuler (int &n){
    vector <set <int>> dske (105);
    vector <int> vao (105  ,0) , out (105,0);
    for (int i = 1;  i <= n ; i++){
        cin >> sz;
        for (int j = 0 ; j < sz ; j++){
            int x;
            cin >> x;
            a[i][x] = 1;
        }
    }
    for (int i = 1;  i <= n ; i++){
        for (int j = 1;  j <= n ; j++){
            if (a[i][j]){
                dske[i].insert(j);
                dske[j].insert(i);
                out[i]++;
                vao[j]++;
            }
        }
    }
    vector <bool> vs (105 , false);
    cnt = 0 ;
    dfs (dske , 1 ,vs);
    if (cnt < n) return 0;
    int s = 0  , t = 0;
    for (int i = 1;  i <= n ; i++){
        if (vao[i] == out [i] ) continue;
        else if (vao[i] == out [i] + 1) s++;
        else if (vao[i] == out [i] - 1) t++;
        else return 0;
    } 
    if (s == 0 && t == 0) return 1;
    else if (s == 1 && t == 1) return 2;
    else return 0;
}
void euler (int n){
    int u ;
    cin >> u;
    vector <set <int>> dske (105);
    for (int i = 1;  i <= n ; i++){
        cin >> sz;
        for (int j = 0 ; j < sz ; j++){
            int x;
            cin >> x;
            a[i][x] = 1;
        }
    }
    for (int i = 1;  i <= n ; i++){
        for (int j = 1;  j <= n ; j++){
            if (a[i][j]){
                dske[i].insert(j);
            }
        }
    }
    stack <int> st;
    st.push(u);
    vector <int> c;
    while (!st.empty()){
        int v = st.top();
        if (!dske[v].empty()){
            int w = *dske[v].begin();
            st.push(w);
            dske[v].erase(w);
        }
        else {
            c.push_back(v);
            st.pop();
        }
    }
    for (int i = c.size() - 1; i >= 0 ; i--){
        cout << c[i] << " ";
    }
}
int main (){
    int t  , n;
    cin >> t >> n;
    if (t == 1) cout << checkeuler (n) << endl;
    else euler (n);

}
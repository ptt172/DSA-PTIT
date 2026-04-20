#include <bits/stdc++.h>
using namespace std;

int n , m;
vector <int> a[20005];
bool vs[20005];
void dfs (int u ,int removed){
    vs[u] = true;
    for (int v : a[u]){
        if (v == removed) continue;
        if (!vs[v]){
            dfs (v , removed);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0 ; i< m ; i ++){
        int u , v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
        for (int i = 1 ; i<= n ;i++){
            memset (vs , 0  ,  sizeof (vs));
            int cmp = 0;
            for (int j = 1; j<= n ;j++){
                if (j == i) continue;
                if (!vs[j]){
                    dfs (j , i);
                    cmp ++;
                }
            }
        cout << cmp << endl;
    }
    return 0;
}
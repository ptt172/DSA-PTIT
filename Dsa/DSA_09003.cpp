#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
        int v , e;
        cin >> v >> e;
        vector <vector <int>> g (v + 1);
        while (e--){
            int u , v;
            cin >> u >> v;
            g[u].push_back (v);
        }
        for (int i = 1 ; i<= v ; i++){
            cout << i << ": ";
            for (int j : g[i]) cout << j << " ";
            cout << endl;
        }
    }
}
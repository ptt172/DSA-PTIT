#include <bits/stdc++.h>
using namespace std;

int main (){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t , n;
    cin >> t >> n;
    vector <vector <int>> a (n , vector <int> (n));
    for (int i = 0;  i< n ; i++){
        for (int j = 0; j < n ; j++){
            cin >> a[i][j];
        }
    }
    if (t == 1) {
        for (int i = 0 ; i< n ; i++){
            int degin = 0 , degout = 0;
            for (int j = 0 ; j < n ;j++){
                degin += a[i][j];
                degout += a[j][i];
            }
            cout << degout << " " << degin << endl;
        }
    }
    if ( t== 2) {
        vector <pair <int,int>> ed;
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ;  j< n ; j++){
                if (a[i][j]) ed.push_back ({i , j});
            }
        }
        vector <vector <int>> res (n , vector <int> (ed.size () ,0));
        for (int k = 0 ; k < ed.size () ; k++){
            int u = ed[k].first , v = ed[k].second;
            res[u][k] = 1;
            res[v][k] = -1;

        }
        cout << n << " " << ed.size () << endl;
        for (int i = 0 ; i< n ; i++){
            for (int j = 0 ; j < ed.size () ;j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
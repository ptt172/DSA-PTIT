#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("DT.INP" ,"r" , stdin);
    freopen("DT.OUT","w",stdout);
    int t , n , m;
    cin >> t >> n >> m;
    vector <int> cnt (n + 1 , 0);
    vector <set<int>> dske (n + 1);
    for (int i = 1 ; i<= m ; i++){
        int x , y;
        cin >> x >> y;
        cnt[x] ++ ;
        cnt [y] ++;
        dske[x].insert (y);
        dske[y].insert (x);
    }
    if (t == 1) {
        for (int i = 1;  i<= n  ; i++) cout << cnt [i] << " ";
    }
    else {
        cout << n << endl;
        for (int i = 1;  i<= n  ;i++){
            cout << dske[i].size () << " ";
            for (auto x : dske[i]) cout << x << " ";
            cout << endl;
        }
    }
}    
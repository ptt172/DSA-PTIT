#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("DT.INP" ,"r" , stdin);
    freopen("DT.OUT","w",stdout);
    int t , n; 
    cin >> t >> n;
    vector <vector <int>> a (n + 1 , vector <int> (n + 1));
    vector <int> cnt ( n + 1 , 0);
    vector <set <int>> dske (n + 1);
    for (int i = 1 ; i<= n ; i++) {
        for (int j = 1; j <= n ; j++){
            cin >> a[i][j];
            if (a[i][j] && j >= i + 1){
                cnt [i] ++ ;
                cnt [j] ++ ;
                dske[i].insert (j);
                dske[j].insert (i);
            }
        }
    }
    if (t == 1) {
        for (int i = 1 ; i<= n ; i++){
            cout << cnt [i] << " ";
        }
    }
    else {
        cout << n << endl;
        for (int i = 1 ; i <= n ; i++){
            cout << dske[i].size () << " ";
            for (int c : dske[i]) cout << c << " ";
            cout << endl; 
        } 
    }
    return 0;
}
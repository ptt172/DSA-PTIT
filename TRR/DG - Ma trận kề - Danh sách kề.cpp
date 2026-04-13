#include <bits/stdc++.h>
using namespace std;

int main(){
    int t , n  ;
    cin >> t >> n;
    vector <vector <int>> a (n + 1 , vector <int> (n + 1));
    for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
        cin >> a[i][j];
    }
}
    if (t == 1) {
        for (int i = 1; i <= n ; i++){
            int degvao = 0 , degra = 0;
            for (int j = 1;  j<= n ; j++ ){
                degvao += a[j][i];
                degra += a[i][j];
            }
            cout << degvao << " " << degra << endl;
        }
    }
    else {
        cout << n << endl;
        for (int i = 1 ; i<= n ; i++){
            vector <int> adj;
            for (int j = 1 ; j <= n ; j++){
                if (a[i][j] == 1) {
                    adj.push_back (j);
                }
            }
            cout << adj.size () << " ";
            for (int x : adj ) cout << x << " ";
            cout << endl;
        }
    }
    

    return 0;
}
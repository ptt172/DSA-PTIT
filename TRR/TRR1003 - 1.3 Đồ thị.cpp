#include <bits/stdc++.h>
using namespace std;

int main() {
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
    int t , n ;
    cin >> t >> n;
    vector <vector <int>> a (n + 1 , vector <int>(n + 1));
    vector <int > cnt (n + 1 , 0);
    set <pair<int , int>> dsc ;
    for (int i = 1 ; i<= n ; i++){
        for (int j = 1;  j<= n ; j++){
            cin >> a[i][j];
            if (a[i][j] && j >= i + 1){
                cnt [i] ++ ;
                cnt [j] ++ ;
                dsc.insert ({min (i , j) , max (i , j)});
            }
        }
    }
    if (t == 1) {
        for (int i = 1;  i<= n ; i++) cout << cnt [i] << " ";
    }
    else {
        cout << n << " " << dsc.size () << endl;
        for (int i = 1;  i<= n ; i++){
            for (auto c : dsc){
                if (c.first == i || c.second == i) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
   
   int t , n , m;
   cin >> t >> n >> m;
   vector <int> cnt (n + 1 , 0);
   vector <vector <int>> a (n + 1 , vector <int>(n + 1 , 0));
   for (int i = 1;  i <= m ; i++){
    int x , y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
    cnt [x] ++ ;
    cnt [y] ++;
   }
   if (t == 1) {
    for (int i = 1 ; i <= n ; i++) cout << cnt [i] << " ";
   }
   else {
    cout << n << endl;
    for (int i = 1; i <= n ; i++){
        for (int j = 1;  j<= n ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
   }
}
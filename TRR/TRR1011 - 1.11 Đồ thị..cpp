#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n , m;
   cin >> t >> n >> m;
   vector <int > cnt (n + 1 , 0);
   vector <vector <int>> a (n + 1 , vector <int> (n + 1 , 10000));
   for (int i = 1 ; i <= m ; i++){
    int x , y , z;
    cin >> x >> y >> z;
    a[x][y] = a[y][x] = z;
    cnt [x] ++ ;
    cnt [y] ++;
   } 
   if (t == 1){
    for (int i = 1;  i<= n ; i++) cout << cnt [i] << " ";
   }
   else {
    cout << n << endl;
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            if (i == j) cout << "0 ";
            else cout << a[i][j] << " ";
    }
    cout << endl;
   }
}
}
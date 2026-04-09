#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n , m  ;
   cin >> t >> n >> m;
   map <int,int> vao , ra;
   vector <vector <int>> a (n + 1 , vector <int> (n + 1 , 10000));
   for (int i = 1;  i<= m ; i++){
      int x , y , z;
      cin >> x >> y >> z;
      a[x][y] = z;
      vao [y] ++ ;
      ra [x] ++ ;
   }
   if (t == 1) for (int i = 1;  i<= n ; i++) cout << vao [i] << " " << ra [i] << endl;
   else {
      cout << n << endl;
      for (int i = 1 ; i <= n  ;i++){
         for (int j = 1;  j <= n ; j++){
            if (i == j) cout << "0 ";
            else cout << a[i][j] << " ";
         }
         cout << endl;
      }
   }

}

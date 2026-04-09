#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n;
   cin >> t >> n;
   vector <int> cnt (n + 1 , 0);
   set <vector <int>> dsc;
   for (int i = 1; i <= n ; i++){
       int x ;
       cin >> x;
       while (x --) {
        int j ;
        cin >> j;
        cnt [i] ++;
        dsc.insert( {min(i , j) , max (i , j)});
       }
   }
   if (t == 1) {
    for (int i = 1 ; i<= n ; i++){
        cout << cnt [i] << " ";
    }
   }
   else {
    cout << n << " " << dsc.size () << endl;
    for (auto v : dsc) cout << v[0] << " " << v[1] << endl;
   }
}
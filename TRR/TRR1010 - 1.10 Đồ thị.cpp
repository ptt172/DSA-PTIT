#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t,  n ;
   cin >> t >> n;
   set <pair <int, int >> dsc ;
   vector <int> cnt (n + 1,0);
   vector <vector <int>> a (n + 1 , vector <int> (n + 1));
   for (int i = 1 ; i<= n ; i++){
    for (int j = 1;  j <= n ; j++){
        cin >> a[i][j] ;
        if (a[i][j] <= 50 && j > i){
            cnt [i] ++ ;
            cnt [j] ++ ;
            dsc .insert ({min (i , j) , max (i , j)});
        }
    }
   }
   if (t == 1) {
    for (int i =1 ; i <= n ; i++) cout << cnt[i] << " ";
   }
   else {
    cout << n << " " << dsc.size() << endl;
    for (auto c : dsc) cout << c.first << " " << c.second << " " << a[c.first][c.second] << endl;
   }
}   
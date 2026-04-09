#include <bits/stdc++.h>

using namespace std;
int main (){
   //freopen("DT.INP","r",stdin);
   //freopen("DT.OUT","w",stdout);
   int t , n ;
   cin >> t >> n;
   vector <pair <int,int>> res;
   vector <int> cnt (n + 1 ,0);
   vector <vector <int>> a (n + 1 , vector <int> (n + 1));
   for (int i = 1; i <= n ; i++){
    for (int j = 1; j <= n ; j++){
        cin >> a[i][j];
        if (a[i][j] && j > i) {
            cnt [i] ++;
            cnt [j] ++;
            res.push_back ({i , j});
        } 
    } 
   }
   if (t == 1) for (int i = 1; i <= n ; i++) cout << cnt [i] << " ";
   else {
    cout << n << " " << res.size() << endl;
    for (auto x : res) cout << x.first << " " << x.second << endl; 
   }
}

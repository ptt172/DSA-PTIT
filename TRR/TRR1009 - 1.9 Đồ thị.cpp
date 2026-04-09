#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n;
   cin >> t >> n;
   set <pair <int,int>> dsc ;
   vector <int> cnt (n + 1 , 0);
   for (int i = 1;  i <= n ; i++){
    int x ;
    cin >> x;
    while (x--){
        int j ;
        cin >> j;
        cnt [i] ++ ;
        dsc.insert ({min (i , j) , max (i , j)});
    }
   }
   if (t == 1) {
    for (int i = 1;  i<= n ; i++) cout << cnt[i] << " ";
   }
   else {
    cout << n << " " << dsc.size () << endl;
    for (int i = 1; i <= n ; i++){
        for (auto x : dsc){
            if (x.first == i || x.second == i) cout << "1 ";
            else cout << "0 "; 
        }
        cout << endl;
    }
   }
}
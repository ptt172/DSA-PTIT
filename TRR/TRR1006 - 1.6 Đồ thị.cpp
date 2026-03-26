#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n , m;
   cin >> t >> n >> m;
   vector <int> cnt (n + 1 , 0 );
   vector <pair <int,int>> a;
   for (int i = 1; i <= m ; i++){
    int x , y;
    cin >> x >> y;
    cnt [x] ++ ;
    cnt [y] ++;
    a.push_back ({x , y});
   } 
   if (t == 1){
    for (int i = 1;  i<= n ; i++) cout << cnt [i] << " ";
   } 
   else{
    cout << n << " " << m << endl;
    for (int i = 1 ; i <= n  ;i++){
        for (auto c : a){
            if (c.first == i || c.second == i) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
   }
}
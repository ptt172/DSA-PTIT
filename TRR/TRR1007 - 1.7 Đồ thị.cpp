#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n;
   cin >> t >> n;
   vector <vector <int >> a (n + 1 , vector <int> (n + 1 , 0));
   vector <int> cnt (n + 1 , 0);
   for (int i = 1;  i<= n ; i++){
    int c;
    cin >> c;
    while (c--){
        int j;
        cin >> j;
        a[i][j] = 1;
        cnt [i] ++;
    }
   }
   if (t == 1){
    for (int i =1 ; i <= n ; i++) cout << cnt[i] << " ";
   }
   else {
    cout << n << endl;
    for (int i = 1; i <= n ; i++){
        for (int j = 1;  j <= n ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
   }
}
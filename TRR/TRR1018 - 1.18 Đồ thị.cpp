#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n;
   cin >> t >> n;
   map <int, int > vao ,ra;
   vector <vector <int>> a (n + 1 , vector <int> (n + 1 , 0));
   for (int i = 1;  i<= n ; i++){
    int c;
    cin >> c;
    while (c--) {
        int j;
        cin >> j;
        a[i][j] = 1;
        ra [i] ++ ;
        vao [j] ++ ;
    }
   }
   if (t == 1) for (int i = 1; i <= n ; i++) cout << vao [i] << " " << ra[i] << endl;
   else {
    cout << n << endl;
    for (int i = 1 ; i <= n ;i++){
        for (int j = 1 ; j <= n ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
   }
}   
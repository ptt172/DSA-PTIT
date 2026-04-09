#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n ;
   cin >> t >> n;
   map <int, int > vao , ra;
   vector <vector <int>> dsc;
   for (int i = 1; i <= n ; i ++){
    int c;
    cin >> c;
    while (c--) {
        int j;
        cin >> j;
        ra [i] ++;
        vao[j] ++ ;
        dsc.push_back ({i , j});
    }
   }
   if ( t == 1) for (int i = 1;  i <= n ; i++) cout << vao [i] << ' ' << ra [i] << endl;
   else {
    cout << n << " " << dsc.size () << endl;
    for (auto x : dsc) cout << x[0] << " " << x[1] << endl;
   }

}   
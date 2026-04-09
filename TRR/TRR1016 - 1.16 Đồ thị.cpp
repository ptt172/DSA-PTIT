#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n , m;
   cin >> t >> n >> m;
   map <int, int > vao , ra;
   vector <set <int>> dske (n + 1);
   for (int  i = 1 ; i<= m ;i ++){
    int x , y;
    cin >> x >> y;
    ra[x] ++ ;
    vao [y] ++ ;
    dske[x].insert(y);
   }
   if (t == 1) for (int i = 1; i <= n ; i++) cout << vao[i] << " " << ra [i] << endl;
   else {
    cout << n << endl;
    for (int i = 1;  i<= n ; i++) {
        cout << dske[i].size () << " ";
        for (int x : dske[i]) cout << x << " ";
        cout << endl;
    }
   }
}
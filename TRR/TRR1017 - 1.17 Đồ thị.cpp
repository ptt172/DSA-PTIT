#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t, n , m;
   cin >> t >> n >> m;
   map <int, int> vao , ra;
   vector <vector <int >> dsc ;
   for (int i = 1; i <= m  ; i++){
    int x , y;
    cin >> x >> y;
    ra [x] ++ ;
    vao[y] ++ ;
    dsc.push_back ({x , y});
   }
   if (t == 1) for (int i = 1; i <= n ; i++) cout << vao [i] << " " << ra [i] << endl;
   else {
    cout << n << " " << dsc.size () << endl;
    for (int i = 1;  i<= n ; i++){
        for (auto c : dsc) {
            if (c[0] == i) cout << "1 ";
            else if (c[1] == i) cout << "-1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
   } 

}   
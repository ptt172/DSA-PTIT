#include <bits/stdc++.h>

using namespace std;
int main (){
   freopen("DT.INP","r",stdin);
   freopen("DT.OUT","w",stdout);
   int t , n;
   cin >> t >> n;
   map <int,int> vao , ra;
   vector <vector <int>> dsc;
   for (int i = 1; i<= n ; i++){
    for (int j = 1 ; j <= n ; j++ ){
        int x;
        cin >> x;
        if (x != 10000 && x != 0) {
            dsc .push_back ({i,j,x});
            ra[i] ++;
            vao[j] ++;
        }
    }
}
    if (t == 1) for (int i = 1; i <= n ; i++) cout << vao[i] << " " << ra[i] << endl;
    else {
        cout << n << " " << dsc.size () << endl;
        for (auto x : dsc){
            cout << x[0] << " " << x[1] << " " << x[2] << endl;
        }
    }
}
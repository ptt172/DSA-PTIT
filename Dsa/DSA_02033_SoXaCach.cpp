#include <bits/stdc++.h>
using namespace std;

int n ;
vector <int> a ;
vector <bool> vs;
void in (){
    for (int i = 1 ; i< n ; i++){
        if (abs (a[i] - a[i + 1]) == 1) return;
    }
    for (int i = 1; i<= n ;i++){
        cout << a[i];
    }
    cout << endl;
}
void ql (int i){
    for (int j = 1; j <= n ; j++){
        if (!vs[j]){
            vs[j] = true;
            a[i] = j;
            if (i == n) in ();
            else ql (i + 1);
            vs[j] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        a.resize (n + 1);
        vs.resize (n + 1  , false);
        ql (1);
    }

    return 0;
}
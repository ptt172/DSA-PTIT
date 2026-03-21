#include<bits/stdc++.h>
using namespace std;
int n ;
vector <int> a , x;
vector <bool> vs ;
void ql (int i){
    if (i == n) {
        for (int j = 0 ;  j < n ; j++){
            cout << x[j] << " ";
        }
        cout << endl;
    }
    for (int j = 0 ;j < n ; j++){
        if (!vs[j]){
            vs[j] = true;
            x[i] = a[j];
            ql (i + 1);
            vs[j] = false;
        }
    }
}
int main (){
    cin >> n;
    a.resize (n);
    x.resize (n);
    vs.assign(n,false);
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort (a.begin (), a.end());
    ql (0);
}
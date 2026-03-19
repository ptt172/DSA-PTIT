#include <bits/stdc++.h>
using namespace std;

int n , k , ans;
vector <int> a , b;
void in (){
    int sum = 0 ;
    for (int i = 0  ; i< n ; i++){
        sum += a[i] * b[i];
    }
    if (sum == k) {
        ans ++ ;
        for (int i = 0 ;  i <n ; i++){
            if (b[i]) cout << a[i] << " ";
        }
        cout << endl;
    }
}
void ql (int i){
    for (int j = 0 ; j <= 1 ; j++){
        b[i] = j;
        if (i == n -1) in ();
        else ql (i + 1);
    }
}
int main() {
    cin >> n >> k;
    a.resize (n);
    b.resize (n);
    for (int &i : a) cin >> i;
    ql (0);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n , stt = 1;
int a[33] , vs [33];
void in (){
    cout << stt ++ << ": ";
    for (int i = 1 ; i <= n ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void ql (int i) {
    for (int j = 1 ; j <= n ; j++) {
        if (!vs[j]){
            a[i] = j;
            vs[j] = 1;
            if (i == n) in ();
            else ql (i + 1);
            vs[j] = 0;
        }
    }
}


int main() {
    cin >> n;
    ql(1);
    return 0;
}
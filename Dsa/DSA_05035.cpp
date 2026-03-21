#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long a[11] , f[101];
void solve (){
        for (int i = 1;  i<= 10 ; i++){
            a[i] = 1;
        }
        f[1] = 10;
        for (int i = 2;  i <= 100 ; i++){
            f[i] = 0;
            for (int j = 1;  j<= 9 ; j++){
                long long s = 0;
                for (int k = j ; k <= 9 ; k++){
                    s+= a[k];
                }
                a[j] = s;
                f[i] = (f[i] + s) % mod;
            }
        }
}
int main (){
    solve();
    int t;
    cin >> t;
    while (t--){
        int n ;
        cin >> n;
        cout << f[n] << endl;
    }

}
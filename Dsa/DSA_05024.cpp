#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int main (){
    int t;
    cin >> t;
    while (t--){
        int n , k ;
        cin >> n >> k;
        vector <int> a(n);
        for (int &x : a) cin >> x;
        vector <int> dp (k + 1, 0);
        dp[0] = 1;
        for (int i = 1 ; i <= k ; i++){
            for (int x : a) {
                if (i >= x) {
                    dp[i] = (dp[i] + dp[i-x]) %mod;
                }
            }
        }
        cout << dp[k] << endl;
    }

}
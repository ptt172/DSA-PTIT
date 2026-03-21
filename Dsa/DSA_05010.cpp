#include <bits/stdc++.h>
using namespace std;

// gặp dãy con dài tổng chia hết k lưu ý : dp[i][j] = max (dp[i-1][j] , dp[i-1] [(j - a[i] + k) % k] + 1)
int main (){
    int n , k , t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        int a[1005] , dp[1005][1005];
        for (int i = 1; i <= n ; i++) {
            cin >> a[i] , a[i] %= k; // chia dư rút gọn tính toán vd chia dư 3 : mảng 2 1 0 0 0 .
        }
        for (int i = 1 ; i< k ; i ++) dp[0][i] = -1e9;
        dp[0][0] = 0;
        for (int i = 1;  i<= n ; i++){
            for (int j = 0 ; j < k ;  j++){
                dp[i][j] = max (dp[i-1][j] , dp[i - 1][(j - a[i] + k ) % k ] + 1 );
            }
        }
        cout << dp[n][0] << endl;
    }
}
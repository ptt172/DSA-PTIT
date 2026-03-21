#include <bits/stdc++.h>
using namespace std;
// loại bỏ ít nhất = n - lps trong đó lps : xâu con đối xứng dài nhất . 
// lps = lcs (s , reverse (s)) 

int main (){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int n = s.size ();
        string a = s;
        reverse (a.begin () , a.end ());
        int dp[104][104] = {0};
        for (int i =  1;  i <= n ; i++){
            for (int j = 1 ; j <= n ; j++){
                if (s[i - 1] == a[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max (dp[i-1][j],dp[i][j-1]);
            }
        }
        int lps = dp[n][n];
        cout << n - dp[n][n] << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int dp [45][45] ;

int main (){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
    int n = s.size ();
    memset(dp,0,sizeof(dp));
    for (int i = 0 ; i < n ; i++) dp[i][i] = 1;
        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2)
                    dp[i][j] = 2;
                else if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout << n - dp[0][n-1] << endl;
    }
}
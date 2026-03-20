#include<bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
    int n;
    cin >> n;
    vector <double> a (n) , b (n);
    for (int i = 0 ; i< n ;i++){
        cin >> a[i] >> b[i];
    }
    vector <int> dp (n , 1);
    int ans = 1 ;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < i ; j++){
            if (a[j] < a[i] && b[j] > b[i]){
                dp[i] = max (dp[i],dp[j] + 1);
            }
        }
        ans = max (ans , dp[i]);
    }
    cout << ans << endl;
}
}
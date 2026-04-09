#include<bits/stdc++.h>
using namespace std;

int main (){
    int n , q;
    cin >> n >> q;
    long long h [100005];
    int tiep [100005] , dp [100005];
    for (int i = 1 ; i <= n ; i++) cin >> h[i];
    stack <int > st;
    for (int i = n ; i >= 1 ; i --){
        while (!st.empty () && h[st.top ()] <= h[i]) st.pop ();
        if (st.empty ()) tiep[i] = 0;
        else tiep[i] = st.top ();
        st.push (i);
    }
    for (int i = n ; i >= 1;  i --){
        if (tiep[i] == 0) dp[i] = 0;
        else dp[i] = dp[tiep[i]] + 1;
    }
    while (q--){
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }
}
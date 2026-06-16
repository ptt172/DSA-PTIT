#include <bits/stdc++.h>
using namespace std;


int main (){
    int t , n , k;
    cin >> t;
    int a[105];
    map <int,int> mp;
    while (t--){
        cin >> n >> k;
        for (int i = 1; i<= n ;i++){
            cin >> a[i];
            mp[a[i]] ++;
    }
        int i = k;
        while (i >= 1 && a[i] == n- k  + i) i --;
        if (i == 0) {
            cout << k;
            return 0 ;
        }
        else {
            a[i] ++;
            while (i < k ){
                a[i+1] = a[i] + 1;
                i ++;
            } 
        }
        int ans = 0;
        for (int i = 1; i<= k ;i++){
            if (!mp[a[i]]) ans ++;
        }
        cout << ans << endl;
    }
}
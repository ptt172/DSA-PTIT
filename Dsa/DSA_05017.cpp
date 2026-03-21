#include <bits/stdc++.h>
using namespace std;
// độ dài là l + r - 1 tổng : l + r - a[i] lưu ý : dãy con không liên tiếp nên không thể so sánh a[i] với a[i-1] ...
int main (){
    int t;
    cin >> t;
    while (t--){
        int n ;
        cin >> n;
        int a[102] , l [102] , r [102];
        memset(l , 0 ,sizeof(l)); // phai memset neu khong cac test sau se bi sai
        memset(r , 0 ,sizeof(r));
        for (int i = 1 ; i <= n ; i++) cin >> a[i];
        for (int i  = 1 ; i <= n ; i++){
            l[i] = a[i];
            for (int j = 0 ; j < i ; j++){
                if (a[j] < a[i])
                l[i] = max (l[i] , l[j] + a[i]);;
            }
        }
        for (int i = n; i >= 1 ; i --){
            r[i] = a[i];
            for (int j = n  ; j > i ; j--){
                if (a[i] > a[j]){
                r[i] = max (r[i] , r[j] + a[i]);
                }
            }
        }
        int res = 0;
        for (int i = 1 ; i <= n ; i++){
            res = max (res , l[i] + r[i] - a[i]);
        }
        cout << res << endl;
    }
}
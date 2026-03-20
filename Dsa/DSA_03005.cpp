#include <bits/stdc++.h>
using namespace std;
// ý tưởng : tổng của mảng cố định nên muốn tìm hiệu lớn nhất : 2 * a[i] chạy từ i đến k phải min 
// vì tổng bao gồm cả k số phần tử nên : sum += a[i] bao gồm cả k nên muốn tìm hiệu dãy 1 - dãy 2 lấy sum -= 2 lần của dãy k 
int main (){
    int t;
    cin >> t;
    while (t--){
        int n , k;
        cin >> n >> k;
        vector <int> a (n);
        int sum = 0;
        for (int &x : a){
            cin >> x;
            sum += x;
        }
        sort (a.begin (),a.end());
        k = min (k , n - k);
        for (int i = 0 ; i< k ; i++){
            sum -= 2 * a[i];
        }
        cout << sum << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin >> t;
    long long n;
    while (t--){
        cin >> n;
        queue <long long> q;
        q.push (1);
        long long res = 0;
        while (1){
            long long c = q.front();
            q.pop ();
            if (c <= n) {
                res ++;
            }
            else break;
            q.push (c * 10);
            q.push (c * 10 + 1);
        }
        cout << res << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

int main (){
    int t ;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        queue <long long> q;
        q.push (1);
        int res = 0;
        while (1){
            long long m = q.front();
            if (m % n == 0) {
                cout << m << endl;
                break;
            }
            q.pop ();
            q.push (m * 10);
            q.push (m * 10 + 1);
        }
    }
}
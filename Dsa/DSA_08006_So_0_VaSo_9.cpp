#include <bits/stdc++.h>
using namespace std;

int main (){
    int t ;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        queue <long long> q;
        q.push (9);
        while (!q.empty()){
            long long m = q.front ();
            if (m % n == 0){
                cout << m << endl;
                break;
            }
            q.pop ();
            q.push (m * 10);
            q.push (m * 10 + 9);
    }
    }
}
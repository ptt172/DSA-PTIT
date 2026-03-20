#include<bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <long long >a (n);
        for (long long &x : a) cin >> x;
        long long x  = 0 , y = 0;
        sort (a.begin () , a.end());
        for (int i = 0 ; i < n ; i++){
            if (i % 2 == 0) x = x * 10 + a[i];
            else y = y * 10 + a[i];
        }
        cout << x + y << endl;
    }
}
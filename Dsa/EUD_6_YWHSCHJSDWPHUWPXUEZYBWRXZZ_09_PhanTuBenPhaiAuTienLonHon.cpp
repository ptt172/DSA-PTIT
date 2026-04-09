#include <bits/stdc++.h>
using namespace std;


int main (){
    int t;
    cin >> t;
    while (t--){
        int n ;
        cin >> n;
        vector <int> a (n + 1) , r (n + 1);
        for (int i = 0 ; i < n ; i++) cin >> a[i];
        stack <int> v;
        for (int i = n - 1; i >= 0 ; i--){
            while (!v.empty () && v.top () <= a[i]) v.pop ();
            if (v.empty ()) r[i] = -1;
            else r[i] = v.top ();
            v.push (a[i]);
        }
        for (int i = 0 ; i< n ; i++) cout << r[i] << " ";
        cout << endl;
    }
}
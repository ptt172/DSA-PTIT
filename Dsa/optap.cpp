#include <bits/stdc++.h>
using namespace std;



int main (){
    int t;
    cin >> t;
    while (t--){
       string s;
       cin >> s;
       stack <int> v;
       for (int i = 0  ;i<= s.size () ;i++){
            v.push (i + 1);
            if (i == s.size () || s[i] == 'I'){
                while (!v.empty ()){
                    cout << v.top();
                    v.pop ();
                }
            }
       }
       cout << endl;
    }
}
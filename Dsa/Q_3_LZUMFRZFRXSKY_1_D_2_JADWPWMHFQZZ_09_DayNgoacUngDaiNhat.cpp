#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack <char> v;
        int mo = 0 , dong = 0;
        for (auto x : s){
            if (x == '('){
                v.push (x);
                mo ++;
            }
            else {
                if (!v.empty () && v.top () =='('){
                    v.pop ();
                    mo --;
                }
                else {
                    dong ++;
                    v.push (x);
                }
            }
            }
        int ans = mo /2 + dong /2; 
        ans += mo % 2 + dong % 2;
        cout << ans << endl;
        }
}
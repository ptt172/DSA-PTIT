#include <bits/stdc++.h>
using namespace std;

bool ktra (char c){
    return c == '*' || c == '/' || c == '+' || c == '-';
}
int main (){
    int t ;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;
        cin >> s;
        stack <string> v;
        for (int i = s.size () - 1 ; i >= 0 ;i--){
            char x = s[i];
            if (ktra (x)){
                string a = v.top () ;
                v.pop ();
                string b = v.top ();
                v.pop ();
                string res = a + b + x;
                v.push (res);
            }
            else v.push (string (1 , x));
        }
        cout << v.top () << endl;
    }
}
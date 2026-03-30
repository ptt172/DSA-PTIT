#include <bits/stdc++.h>
using namespace std;

bool ktra (string c){
    return c == "*" || c == "/" || c == "+" || c == "-";
}
int main (){
    int t ;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;
        cin >> s;
        stack <string> v;
        for (int i = 0 ; i <= s.size () ;i++){
            string x = string (1 , s[i]);
            if (ktra (x)){
                string a = v.top () ;
                v.pop ();
                string b = v.top ();
                v.pop ();
                string res = "(" + a + x + b + ")";
                v.push (res);
            }
            else v.push (x);
        }
        cout << v.top () << endl;
    }
}
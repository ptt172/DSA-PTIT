#include <bits/stdc++.h>
using namespace std;

int uutien (char c){
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main (){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack <char>st;
        string res ;
        for (char c : s){
            if (isalpha (c) || isdigit (c)) res += c;
            else if (c == '('){
                st.push (c);
            }
            else if (c == ')'){
                while (!st.empty () && st.top () != '('){
                    res += st.top ();
                    st.pop ();
                }
                if (!st.empty()) st.pop ();
            }
            else {
                while (!st.empty () && uutien (st.top()) >= uutien (c) ){
                    res += st.top ();
                    st.pop ();
                }
                st.push (c);
            }
        }
        while (!st.empty ()){
            res += st.top ();
            st.pop ();
        }
        cout << res << endl;
    }
}
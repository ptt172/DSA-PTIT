#include <bits/stdc++.h>
using namespace std;

int ptoan (char c){
    if (c == '^') return 4;
    if (c == '*' || c == '/') return 3;
    if (c == '+' || c == '-') return 2;
    return 1;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        string res = "";
        stack <char> st;
        for (int i = 0 ; i< s.size () ; i++){
            if (s[i] == '(') st.push (s[i]);
            else if (s[i] == ')'){
                while (st.top () != '('){
                    res += st.top ();
                    st.pop();
                }
                st.pop();
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
                while (!st.empty() && ptoan (st.top ()) >= ptoan (s[i])){
                    res += st.top ();
                    st.pop ();
                }
                st.push (s[i]);
            }
            else res += s[i];
        }
        while (!st.empty()){
            if (st.top () != '(') res += st.top();
            st.pop ();
        }
        cout << res << endl;
    }

    return 0;
}
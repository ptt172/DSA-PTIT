#include <bits/stdc++.h>

using namespace std;
bool check(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool check(string s) {
    stack<char> st;
    for (char x : s) {
        if (x != ')') {
            st.push(x);
        } else {
            bool ok = false;
            while (!st.empty()) {
                char c = st.top(); 
                st.pop();

                if (check(c)) ok = true;
                if (c == '(') break;
            }
            if (!ok) return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        if (check(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<string> st;
        for (char c : s) {
            if (isOp(c)) {
                string b = st.top(); st.pop();
                string a = st.top(); st.pop();
                string res = string(1, c) + a + b;
                st.push(res);
            } else {
                st.push(string(1, c));
            }
        }
        cout << st.top() << '\n';
    }
}
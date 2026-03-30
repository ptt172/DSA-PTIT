#include <bits/stdc++.h>

using namespace std;
bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool check(string s) {
    stack<char> st;

    for (char x : s) {
        if (x != ')') {
            st.push(x);
        } else {
            bool hasOp = false;

            while (!st.empty()) {
                char c = st.top(); 
                st.pop();

                if (isOp(c)) hasOp = true;
                if (c == '(') break;
            }
            if (!hasOp) return true;
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
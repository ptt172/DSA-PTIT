#include <bits/stdc++.h>
using namespace std;

int ktra (string s){
    int n = s.size () ;
    stack <char> st;
    for (int i = 0 ; i< n ; i++){
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') st.push (s[i]);
        else {
        if (st.empty()) return 0;
        char in = st.top () , out = s[i];
        if ((in == '(' && out == ')') || (in == '[' && out == ']') || (in == '{' && out == '}')) st.pop ();
        else return 0;
    }
}
    return st.empty ();
}

int main (){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;
        cin >> s;
        if (ktra (s)) cout << "YES\n";
        else cout << "NO\n";
    }
}
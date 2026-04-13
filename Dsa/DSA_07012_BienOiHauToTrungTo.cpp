#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack <string> st;
        for (int i = 0 ; i < s.size () ; i ++){
            string x = string (1,s[i]) ; // chuyển char -> string;
            if (x == "+" || x == "-" || x == "*" || x == "/"){
                string b = st.top ();st.pop();
                string a = st.top ();st.pop();
                st.push ("(" + a + x + b + ")");
            }
            else st.push (x);
        }
        cout << st.top() << endl;
    }
    

    return 0;
}
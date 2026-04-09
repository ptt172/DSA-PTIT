#include <bits/stdc++.h>
using namespace std;

string solve (string s){
    int n = s.size ();
    string res = "";
    stack <int> st;
    for (int i = 0 ; i <= n ;i++){
        st.push (i + 1);
        if (i == n || s[i] == 'I'){
            while (!st.empty ()){
                res += to_string (st.top ());
                st.pop ();
            }
        }
    }
    return res ;
}
int main (){
    int t;
    cin >> t;
    for (int i = 1 ; i <= t ; i++){
        string s;
        cin >> s;
        cout << "Test " << i << ": " << solve (s) << endl;
    }
}
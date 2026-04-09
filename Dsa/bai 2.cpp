#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;
        getline (cin , s);
        int n = s.size ();
        vector <int > a (n , 0);
        stack <int> st;
        for (int i = 0 ; i < n ;i++){
            if (s[i] == '(') st.push (i);
            else if (s[i] == ')') {
            if (!st.empty ()){
                a[st.top ()] = 1;
                a[i] = 2;
                st.pop ();
            }
            else a[i] = -1;
        }
    }
    while (!st.empty ()){
        a[st.top ()] = -1;
        st.pop ();
    }   
    string res = "";
    for (int i = 0 ; i < n ; i++){
        if (a[i] == 1) res += "0";
        else if (a[i] == 2) res += "1";
        else if (a[i] == -1) res += "-1";
        else res += s[i];
    }
    cout << res << endl;

}

}
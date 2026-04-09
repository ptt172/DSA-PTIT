#include<bits/stdc++.h>
using namespace std;


int main (){
    int k ;
    cin >> k;
    cin.ignore ();
    while (k--){
        string s;
        getline (cin , s);
        string t = "";
        for (char c : s){
            if (c != ' ') t += c;
        }
        s = t;
        int n = s.size ();
        vector <int> a (n , 1);
        stack <int> st;
        for (int i = 0 ; i < n ;i ++){
            if (s[i] == '('){
                st.push (i);
                if (i == 0 || s[i - 1] == '+') {
                    a[i] = 0;
                } 
            }
            else if (s[i] == ')'){
                int mo = st.top (); st.pop ();
                if (a[mo] ==0) {
                    a[i] =0;
                }
            }
        }
        for (int i = 0 ; i < n ;i++){
            if (a[i]) cout << s[i];
        }
        cout << endl;
    }
}
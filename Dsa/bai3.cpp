#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    cin .ignore ();
    while (t--){
        string s;
        getline (cin , s);
        stack <int> st;
        int n = s.size ();
        vector <int> a (n , 0);
        int cnt = 0 ;
        for (int i = 0 ; i<n ; i++){
            if (s[i] == '(') {
                cnt ++;
                st.push (cnt);
                a[i] = cnt;
            }
            else if (s[i] == ')') {
                if (!st.empty ()){
                    a[i] = st.top ();
                    st.pop ();
                }
            }
        }
        bool ok = true ;
        for (int i = 0 ; i< n ; i++){
            if (s[i] == '(' || s[i] == ')'){
                cout << a [i] << " ";
                ok = false ;
            }
        }
        cout << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

bool check (string s){
    if (s == "+" || s == "-" || s == "*" || s == "/") return true;
    return false;
}
bool so (string s){
    if (s.size () == 0) return false;
    if (s[0] == '-' && s.size () > 1){
        for (int i = 1 ;  i< s.size () ; i++){
            if (!isdigit (s[i])) return false;
        }
        return true;
    }
    for (int i = 0 ; i < s.size () ; i++){
        if (!isdigit (s[i])) return false;
    }
    return true;
}
long long calc (long long a , long long b , string op){
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}
int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <string> a (n );
        for (int i = 0 ; i<n ; i++) cin >> a[i];
        stack <long long > st; 
        for (int i = 0 ; i < n ; i ++){
            if (so (a[i])) {
                st.push (stoll (a[i]));
            }
            else {
                long long y = st.top(); st.pop();
                long long x = st.top(); st.pop();
                st.push (calc (x , y , a[i]));
            }
        }
    cout << st.top () << endl;
}
}
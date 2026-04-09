#include<bits/stdc++.h>
using namespace std;
bool check (string s){
    return (s == "+" || s == "-" || s == "*" || s == "/") ;
}
long long calc (long long a , long long b , string op){
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    return a / b;
}
int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <string> a (n );
        for (int i = 0 ; i<n ; i++) cin >> a[i];
        stack <long long> st;
        long long res ;
        if (check (a[0])){
        for (int i = n - 1 ; i>=0 ; i--){
            if (!check (a[i])){
                st.push (stoll (a[i]));
            }
            else {
                long long m = st.top(); st.pop();
                long long n = st.top(); st.pop();
                st.push (calc (m , n , a[i]));
            }
        }
        res = st.top();
    }
    else {
        stack <long long > c; 
        for (int i = 0 ; i<n ; i ++){
            if (!check (a[i])){
                c.push (stoll (a[i]));
            }
            else {
                long long n = c.top(); c.pop();
                long long m = c.top(); c.pop();
                c.push (calc (m , n , a[i]));
            }
        }
        res = c.top();
    }
    cout << res << endl;
}
}
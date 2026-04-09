#include<bits/stdc++.h>
using namespace std;


int main (){
    long long m , n;
    cin >> m >> n;
    vector <long long> a (n) , b (n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        b[i] = m - a[i];
    }
    long long ans = 0;
    stack <int> st;
    for (int i = 0 ; i <= n ; i++){
        long long cur = (i == n) ? 0 : a[i];
        while (!st.empty () && a[st.top ()] > cur){
            long long h = a[st.top ()];
            st.pop ();
            long long w = (st.empty ()) ? i : (i - st.top () - 1);
            ans = max (ans , h * w);
        }
        st.push (i);
    }
    while (!st.empty ()) st.pop ();
    for (int i = 0 ; i <= n ; i++){
        long long cur = (i == n) ? 0 : b[i];
        while (!st.empty () && b[st.top ()] > cur){
            long long h = b[st.top ()];
            st.pop ();
            long long w = (st.empty ()) ? i : (i - st.top () - 1);
            ans = max (ans , h * w);
        }
        st.push (i);
    }
    cout << ans << endl;

}
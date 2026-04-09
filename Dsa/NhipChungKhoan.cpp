#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> a (100005);
        stack <int> st;
        st.push (0);
        for (int i = 1;  i<= n ;i ++){
            cin >> a[i];
            while (st.size () > 1 && a[st.top ()] <= a[i]){
                st.pop ();
            }
            if (st.empty()) cout << i << " ";
            else cout << i - st.top() << " ";
            st.push(i);
        }
        cout << endl;
    }

}
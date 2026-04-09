#include<bits/stdc++.h>
using namespace std;


int main (){
    int n;
    cin >> n;
    vector <long long> a (n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    stack <pair <long long , long long>> st;
    long long res = 0;
    for (int i = 0 ; i < n ; i++){
        long long cnt = 1;
        while (!st.empty () && st.top().first < a[i]){
            res += st.top ().second;
            st.pop ();
        }
        if (!st.empty () && st.top().first == a[i]) {
                long long c = st.top().second;
                res += c;
                cnt += c;
                st.pop ();
            }
                if (!st.empty ()) res ++;
                st.push ({a[i] , cnt} );
    }
            cout << res << endl;
}
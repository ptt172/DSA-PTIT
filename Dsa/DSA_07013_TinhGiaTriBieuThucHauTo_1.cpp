#include <bits/stdc++.h>
using namespace std;
int tinh (int x , int y  , char o){
    if (o == '+') return x + y;
    else if (o == '-') return x - y;
    else if (o == '*') return x * y;
    else if (o == '/') {
        if (y == 0 ) return 0;
        return x/y;
    }
    return 0;
}

int main (){
    int t ;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        stack <int> st;
        for (int i = 0; i < s.size (); i++){
            if (isdigit(s[i])){
                st.push(s[i] - '0');
            }
            else{
                if (st.size() < 2) continue;
                int y = st.top(); st.pop();// đây là hậu tố , tiền tố chạy từ sau về trước và pop x trước
                int x = st.top(); st.pop();
                st.push(tinh(x, y, s[i]));
            }
        }
        cout  << st.top () << endl;
    }

}
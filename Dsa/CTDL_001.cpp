#include <bits/stdc++.h>
using namespace std;
int n ;
string a;

void in (){
    string s = a;
    reverse(s.begin(), s.end());
    if (s == a) { 
    for (char i : a){
        cout << i << " ";
    }
    cout << endl;
}
}
void ql (int i){
    for (int j = 0 ; j <= 1 ; j++){
        a[i] = j + '0';
        if (i == n - 1) in ();
        else ql (i + 1);
    }
}
int main() {
    cin >> n;
    a.resize (n);
    ql (0);
    return 0;
}
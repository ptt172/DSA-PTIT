#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> a(n);

void in (){
    cout << "[";
    for (int i = 0 ; i < a.size() ; i++){
        cout << a[i];
        if (i != a.size () - 1 ) cout << " ";
        else cout << "]";
    }
}
void ql (int i){
    in ();
    cout << endl;
    if (i == 1 ) return ;
    vector <int> b;
    for (int j = 0 ; j < i - 1 ; j ++ ){
        b.push_back (a[j] + a[j + 1]);
    }
    a = b;
    ql (i - 1);
}

int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        a.resize (n);
        for (int &x : a) cin >> x;
        ql (n);
    }
}
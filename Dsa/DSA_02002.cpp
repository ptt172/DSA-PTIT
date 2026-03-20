#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> a(n);
vector <vector <int>> rs;
void ql (int i){
    rs.push_back(a);
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
        reverse (rs.begin () , rs.end());
        for (auto i : rs) {
        cout << "[";
        for (int j = 0; j < i.size(); ++j) {
            cout << i[j];
            if (j != i.size() - 1) cout << " ";
        }
        cout << "] ";
    }
    cout << endl;

    }
}
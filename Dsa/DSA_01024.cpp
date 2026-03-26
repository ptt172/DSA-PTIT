#include <bits/stdc++.h>
using namespace std;
int n , k;
vector <string > a;
int x [100];
void in (){
    for (int i = 1 ; i <= k ; i++){
        cout << a[x[i] - 1] << " ";
    }
    cout << endl;
}
void ql (int i){
    for (int j = x[i - 1] + 1 ; j <= (int)a.size () - k + i ;j ++ ){
        x[i] = j;
        if (i == k) in ();
        else ql (i + 1);
    }
}

int main (){
    cin >> n >> k;
    set<string > s;
    for (int i = 0 ; i < n ; i++){
        string st;
        cin >> st;
        s.insert (st);
    }
    for (auto c : s) a.push_back(c);

    ql (1);
}
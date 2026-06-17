#include <bits/stdc++.h>
using namespace std;

int n , k;
int a[105];
vector <string> v;
void in (){
    for (int i = 1; i<= k ; i++){
        cout << v[a[i]-1] << " ";
    }
    cout << endl;
}
void ql (int i){
    for (int j = a[i - 1] + 1 ; j <= (int)v.size () - k + i ; j++){
        a[i] = j;
        if (i == k) in ();
        else ql (i + 1);
    }
}
int main (){
    cin >> n >> k;
    set <string> se;
    string s;
    for (int i = 0 ; i< n ; i++){
        cin >> s;
        se.insert (s);
    }
    for (string x : se){
        v.push_back (x);
    }
    ql (1);
}
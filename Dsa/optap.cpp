#include <bits/stdc++.h>
using namespace std;


int n;
vector <string> res;
void ql (int mo , int dong , string s){
    if (s.size () == 2*n){
        res.push_back (s);
    }
    if (mo < n){
        ql (mo + 1 , dong , s + "(");
    }
    if (dong < mo){
        ql (mo , dong + 1 , s + ")");
    }
}
int main (){
    cin >> n;
    ql (0 , 0 , "");
    cout << res.size () << endl;
    for (string x : res) cout << x << endl;
}
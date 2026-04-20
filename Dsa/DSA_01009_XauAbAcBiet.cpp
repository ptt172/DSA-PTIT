#include <bits/stdc++.h>
using namespace std;

int n , k;
string s;
vector <string> res;
bool check (string s){
    int cnt =0  , dem = 0 ;
    for (int i = 0 ; i< s.size () ; i++){
        if (s[i] == 'A') dem ++;
        else {
            if (dem == k) cnt ++;
            dem = 0;
        }
    }
    if (dem == k) cnt  ++;
    return cnt == 1;
}
void ql (int i){
    if (i == n) {
        if (check (s)) res.push_back (s);
        return ;
    }
    s[i] = 'A';
    ql (i + 1);
    s[i] = 'B';
    ql (i + 1);
}
int main(){
    cin >> n >> k;
    s = string(n, ' ');
    ql(0);
    cout << res.size() << endl;
    for (auto x : res) cout << x << endl;
    return 0;
}
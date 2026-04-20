#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> a;
vector <pair<int,int>> ed;
vector <bool> vs;
vector <int> parent , num ;
int n , m , s ,t;
int find (int v){
    if (v == parent [v]) return v;
    return parent [v] = find (parent [v]);
}
bool Union (int u , int v){
    int a = find (u) , b= find (v);
    if (a == b) return true;
    if (a != b){
        if (num [a] < num [b]) swap (a,b);
        parent [b] =a;
        num [a] += num [b];
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        ed.clear ();
        a.assign (n + 1 , {});
        parent.resize (n + 1);
        num.assign (n + 1 , 1);
        vs.assign (n + 1 , false);
        for (int i = 1; i <= n ;i++){
            parent [i] = i;
            num[i] = 1;
        }
        for (int i = 0 ; i< m ; i++){
            int u , v;
            cin >> u >> v;
            ed.push_back ({u , v});
        }
        bool found = false;
        for (auto x : ed){
            if (Union (x.first , x.second)){
                cout << "YES\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "NO\n";
    }
    return 0;
}
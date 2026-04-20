#include <bits/stdc++.h>
using namespace std;

int n , m , parent [10005] , num [10005];
void init (){
    for (int i = 1; i <= n ; i++){
        parent [i] = i;
        num[i] = 1;
    }
}
int find (int u){
    if (u != parent [u]){
        parent [u] = find (parent [u]);
    }
    return parent [u];
}
void Union (int u , int v){
    int a = find (u) , b  = find (v) ;
    if (a == b) return ;
    if (num[a] < num [b]) swap (a , b);
    parent [b] = a;
    num [a] += num [b];
}

int main(){
    cin >> n >> m;
    init () ; 
    while (m --){
        int u , v;
        cin >> u >> v;
        Union (u , v);
    }
    int c = find (1);
    vector <int> res;
    for (int i = 1;  i<= n ;i++){
        if (find (i) != c){
            res.push_back(i);
        }
    }
    if (!res.empty()) {
        sort (res.begin () , res. end());
        for (auto v : res) cout << v << endl;
    }
    else cout << 0 << endl;


    return 0;
}
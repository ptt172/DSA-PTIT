#include <bits/stdc++.h>
using namespace std ;
// neu hoi dsc thi vector <vector <Int>> 
// dske thi vector <set<int>>
// matran lien thuoc = cach tim dsc mỗi cạnh là 1 cột  
// tu dsk sang dsc thi dung set <vector<int>> dsc.insert (min , max) in ra cạnh
// từ dsk sang dsc in ra ma trận thì dùng set <pair <int,int>> 
// + = ra , - = vao , cột là ra , hàng là vào 

// mảng parent dùng để truy viết parent [105] = {0}

int n , u , v;
vector <bool> vs;
int parent [105]= {0};
int a[105][105] ;
set <int> adj [105];
void demsl (int bd , int kt){

    int cnt = 0;
    for (int i = 1 ; i<= n ;i++){
        if (a[bd][i] == 1 && a[i][kt] == 1){
            cnt ++;
        }
    }
    cout << cnt << endl;
}
void dfs (int s){
    vs[s] = true;
    for (int x : adj [s]){
        if (!vs[x]){
            parent [x] = s;
            dfs (x);
        }
    }
}
void duongdi (int s , int t){
    dfs (s);
    if (!vs[t]){
        cout << 0 << endl;
    }
    else {
        vector <int> path;
        while (t!=s){
            path.push_back (t);
            t = parent [t];
        }
        path.push_back (s);
        reverse (path.begin () , path.end());
        for (int x : path) cout << x << " ";
    }
}

int main (){
    int t;
    cin >> t ;
    cin >>  n >> u >> v;
    vs.assign (n + 5 , false);
    for (int i = 1; i<= n ; i++){
        for (int j = 1 ; j<= n ; j++){
            cin >> a[i][j];
            if (a[i][j]){
                adj[i].insert (j);
            }
        }
    }
    if (t == 1) demsl (u , v);
    else {
        duongdi (u , v);
    }
}
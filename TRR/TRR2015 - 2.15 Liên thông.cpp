#include <bits/stdc++.h>
using namespace std;
int n , e = 0;
int a[105][105] = {};
bool vs[105] = {};
void dfs (int u){
    vs[u]= true;
    for (int i = 1;  i<= n ; i++){
        if (!vs[i] && a[u][i]){
            dfs (i);
        }
    }
}
void checktp (int u){
    vs[u]= true;
    for (int i = 1;  i<= n ; i++){
        if (!vs[i] && (a[u][i] || a[i][u])){
            checktp (i);
        }
    }
}
int check (){
    memset (vs , 0 , sizeof (vs));
    bool ok = true;
    for (int i = 1 ; i <= n ; i++){
        dfs (i);
        for (int v = 1 ; v <= n ;v ++){
            if (!vs[v]) {
                ok = false;
                break;
            }
        }
        memset (vs , 0 , sizeof (vs));
    }
    if (ok) return 1;
    checktp (1);
    for (int i = 1;  i <= n ; i++){
        if (!vs[i]) return 0;
    }
    return 2;
}

int main (){
    cin >> n;
    for (int i = 1;  i<= n ; i++){
        for (int j = 1;  j  <= n ; j++){
            cin >> a[i][j];
        }
    }
        cout << check() << endl;
    return 0;
}
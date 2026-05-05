#include <bits/stdc++.h>
using namespace std;
int a [100][100] , d[100][100] , tiep [100][100] , n ;
int MAX = 10000 ;
void floyd (){
    for (int k = 1 ; k <= n ; k++){
        for (int i = 1;  i<= n ; i++){
            for (int j = 1;  j<= n ; j++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    tiep [i][j] = tiep [i][k];
                }
            }
        }
    }
}
int main (){
    cin >> n;
    for (int i = 1;  i<= n ;i++){
        for (int j = 1; j<= n ; j++){
            cin >> a[i][j] ;
            if (a[i][j] == 0 && i != j) a[i][j] = MAX;
            d[i][j] = a[i][j];
            if (a[i][j] != MAX) tiep [i][j] = j;
            else tiep [i][j] = -1;
        }
    }
    floyd ();
    int u = -1 , v = -1 ;
    int lon = -1;
    for (int i = 1;  i<= n ;i++){
        for (int j = 1; j <= n ;j++){
            if (i != j && d[i][j] > lon && d[i][j] < MAX){
                lon = d[i][j];
                u = i; v = j;
            }
        }
    }
    if (u == -1) {
        cout << "0" << endl;
        return 0;
    }
    cout << u << " " << v << " " << lon << endl;
    int cur = u;
    while (cur != v){
        cout << cur << " ";
        if (u == v) break;
        cur = tiep [cur][v];
    }
    cout << v << endl;
}



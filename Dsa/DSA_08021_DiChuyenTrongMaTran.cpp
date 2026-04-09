#include <bits/stdc++.h> 
using namespace std;

int a[1005][1005] , c[1005][1005] , n , m;
void xl (){
    int i , j , x;
    memset (c , - 1 , sizeof (c));
    queue <pair <int,int>> q;
    q.push ({1,1}); c[1][1] = 0;
    while (!q.empty()){
        pair <int,int> t  = q.front ();
        i = t.first ;
        j = t.second;
        x = a[i][j];
        q.pop ();
        if (c[i][j + x] == -1 ){
            q.push ({i ,  j + x});
            c[i][j + x] = c[i][j] + 1;
        }
        if (c[i + x][j] == -1 ) {
            q.push ({i + x , j}) ;
            c[i+ x][j] = c[i][j] + 1;
        }
        if (c[n][m] != -1) break;
    }
    cout << c[n][m] << endl;
}

int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1 ; i<= n ; i++){
            for (int j = 1;  j<= m ; j++){
                cin >> a[i][j];
            }
        }
        xl ();

    }
}
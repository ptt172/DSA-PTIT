#include<bits/stdc++.h>
using namespace std;

int n , a[11][11];
vector <string> v;
void ql (int i , int j ,string s){
    if (i == n && j == n){
        v.push_back (s);
        return ;
    }
    if (i < n && a[i + 1][j] == 1){
        ql (i + 1 , j , s + 'D');
    }
    if (j < n && a[i][j + 1] == 1){
        ql (i , j + 1 , s + 'R');
    }
}

int main (){
    int t;
    cin >> t;
    while (t--){
        v.clear ();
        cin >> n;
        for (int i = 1;  i<= n ; i++) {
            for (int j = 1 ; j <=  n ;j++){
                cin >> a[i][j];
            }
        }
        if (a[1][1] == 0 || a[n][n] == 0){
            cout << -1 << endl;
            continue;
        }
        ql (1, 1 , "");
		if(v.empty()){
			cout << -1 << endl;
			continue;
		}
		for (auto x : v) cout << x << " ";
		cout << endl;

    }
}
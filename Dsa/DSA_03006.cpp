#include <bits/stdc++.h>
using namespace std;

int main (){
    int t ;
    cin >> t;
    while (t--){
        int n ;
        cin >> n;
        int c [100];
        for (int i = 1 ; i<=n;i++){
            cin >> c[i];
        }
        bool found = false;
        for (int i =  1;  i<=n;i++){
            if (c[i] != i && c[i] != n - i  + 1){
                cout << "No" << endl;
                found = true;
                break;
            }
        }
        if (!found){
            cout << "Yes" << endl;
        }
    }
}
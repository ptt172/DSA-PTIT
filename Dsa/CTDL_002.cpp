#include <bits/stdc++.h>
using namespace std;


int n , k;
int a[105] , x[105];
int cnt =0;
void in (){
    int sum = 0;
    for (int i = 1; i<= n ; i++){
        if (a[i] == 1){
            sum += x[i];
        }
    }
    if (sum == k) {
        cnt ++;
        for (int i = 1 ; i<= n ;i++){
            if (a[i] == 1) cout << x[i] << " ";
        }
        cout << endl;
    }
}
void sinh (int i){
    for (int j = 0 ; j<= 1 ;j ++){
        a[i] = j;
        if (i == n){
            in ();
        }
        else sinh (i + 1);
    }
}
int main () {
    cin >> n >> k;
    for (int i = 1; i<= n ;i++){
        cin >> x[i];
    }
    sinh (1);
    cout << cnt << endl;
}
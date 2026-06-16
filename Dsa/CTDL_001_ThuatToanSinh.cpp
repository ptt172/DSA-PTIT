#include <bits/stdc++.h>
using namespace std;


int n , a[105] ;

void in (){
    for (int i = 1 ; i<= n; i++ ){
        cout << a[i] << " ";
    }
    cout << endl;
}
void sinh (int i){
    int m = (n +  1) / 2;
    for (int j = 0 ; j<= 1 ;j++){
        a[i] = j;
        a[n-i + 1] = j;
        if (i == m) {
            in ();
        }
        else sinh (i + 1);
    }
}
int main (){
    cin >> n;
    sinh (1);
}

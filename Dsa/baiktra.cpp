#include <bits/stdc++.h>
using namespace std;

int n , k;
int a[105];
bool kiemtra (int i){
    int tong = 0;
    for (int i = 2 ; i<= k ; i++){
       tong += abs(a[i] - a[i-1]);
    }
    return tong > k;
}
void in (){
    for (int i = 1;  i<= k ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void ql (int i){
    for (int j = a[i-1] + 1; j <= n - k + i ; j++){
        a[i] = j;
        if (i == k) {
            if (kiemtra(i)) in();
        }
        else ql(i+1);
    }
}

int main (){
    cin >> n >> k;
    a[0] = 0;
    ql(1);
}
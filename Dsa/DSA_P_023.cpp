#include <bits/stdc++.h>
using namespace std;

int n , k;
int a[55];
int stt = 0;
int nt (int n){
    if (n < 2) return 0;
    for (int i = 2;  i *i <= n ; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}
void in (){
    for (int i = 1 ; i <= k ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void ql (int i ) {
    for (int j = a[i-1] + 1 ; j <= n - k + i ; j ++){
        a[i] = j;
        if (i == k){
            stt ++ ;
            if (nt (stt)){
            cout << stt << ": ";
                in ();
            }
        }
        else ql (i + 1); 
    }
}

int main (){
    cin >> n >> k;
    ql (1);
}
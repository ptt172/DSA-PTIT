#include <bits/stdc++.h>
using namespace std;


int n;
int a[105];
int stt = 1;
bool vs[105];
void in (){
    cout << stt << ": ";
    stt ++;
    
    for (int i = 1; i <= n ; i++ ){
        cout << a[i] << " ";
    }
    cout << endl;
}
void ql (int i){
    for (int j = 1; j<= n ;j++){
        if (!vs[j]){
            a[i] = j;
            vs[j] = true;
            if (i == n) {
                in ();
            }
            else {
                ql (i + 1);
            }
            vs[j] = false;
        } 
    }
}
int main (){
    cin >> n;
    ql (1);
}

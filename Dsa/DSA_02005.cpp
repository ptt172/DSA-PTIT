#include<bits/stdc++.h>
using namespace std;
string s , x[11] ;
int check [11];
void in (){
    for (int i = 0 ;  i < s.size() ; i++){
        cout << x[i]; 
    }
    cout << " ";
}
void ql (int i){
    for (int j = 0 ; j < s.size () ; j++ ){
        if (!check[j]){
            x[i] = s[j];
            check [j] = 1;
            if (i == s.size() - 1) in ();
            else ql (i + 1);
            check [j] = 0;
        }
    }
}
int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> s;
        ql (0);
        cout << endl;
    }
    
}
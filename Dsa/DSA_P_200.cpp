#include<bits/stdc++.h>
using namespace std;

int main (){
    int t , n;
    cin >> t;
    while (t--){
        cin >> n;
        vector <int > cnt (10000 , 0);
        for (int i = 0 ; i< n ;i++){
            int x;
            cin >> x;
            cnt [x] ++ ;
        }
        for (int i = 0 ; i < 10000; i ++){
            while (cnt [i]--){
                cout << i << " ";
            }
        }
        cout << endl;

    }
}
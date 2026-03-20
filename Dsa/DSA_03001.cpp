#include <bits/stdc++.h>
using namespace std;
int dx [10] = {1000 , 500 , 200 , 100 ,50 , 20 , 10 ,5 , 2, 1};

int main (){
    int t ;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int count = 0;
        for (int i = 0 ; i < 10 ; i++){
            count += n / dx[i];
            n %= dx [i];
        }
        cout << count << endl;
        
    }
}
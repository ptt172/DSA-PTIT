#include<bits/stdc++.h>
using namespace std;

int main (){
    int n ;
    cin >> n;
    int a [n];
    map<int , int> dem;
    for (int i = 0 ; i <n ; i++){
        cin >> a[i];
        dem [a[i]] ++ ;
    }
    for (int i = 0 ; i<n ; i++){
        if (dem [a[i]] > 0) { cout << a[i] << " ";
        dem [a[i]] = 0;} 
    }
    cout << endl;
}
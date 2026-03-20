#include <bits/stdc++.h>
using namespace std;

string a , b;

int chuyenn (string s){
    int n  = 0;
    for (int i = 0 ;  i< s.size () ; i ++){
        if (s[i] == '6') s[i] ='5';
        n = n * 10 + (s[i] - '0'); 
    }
    return n;
}
int chuyens (string s){
    int n = 0;
    for (int i = 0 ;  i< s.size () ; i ++){
        if (s[i] == '5') s[i] = '6';
        n = n * 10 + (s[i] - '0');
    }
    return n;
}
int main (){
    cin >> a >> b;
    cout <<  chuyenn (a) + chuyenn (b) << " " << chuyens(a) + chuyens (b) << endl;   
}
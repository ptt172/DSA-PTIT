#include<bits/stdc++.h>
using namespace std;

int main (){
    string s;
    cin >> s;
    stack <char> trai , phai;
    for (char c : s){
         if (c == '<') {
            if (!trai.empty ()){
                phai.push (trai.top ());
                trai.pop ();
            }
        }
        else if (c == '>') {
            if (!phai.empty ()){
                trai.push (phai.top ());
                phai.pop ();
            }
        }
        else if (c == '-') {
            if (!trai.empty ()) trai.pop ();
        }
        else trai.push (c);
    }
        string res = "";
        while (!trai.empty ()){
            res += trai.top ();
            trai.pop ();
        }
        reverse (res.begin () , res.end ());
        while (!phai.empty ()){
            res += phai.top ();
            phai.pop ();
        }
        cout << res << endl;
}
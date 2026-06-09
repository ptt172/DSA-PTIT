#include <bits/stdc++.h>
using namespace std ;
// neu hoi dsc thi vector <vector <Int>> 
// dske thi vector <set<int>>
// matran lien thuoc = cach tim dsc mỗi cạnh là 1 cột  
// tu dsk sang dsc thi dung set <vector<int>> dsc.insert (min , max) in ra cạnh
// từ dsk sang dsc in ra ma trận thì dùng set <pair <int,int>> 
// + = ra , - = vao , cột là ra , hàng là vào 
int main (){
    int t , n ;
    cin >> t >> n ;
    vector <vector <int>> a (n + 1 , vector <int> (n + 1 ,0));
    map <int,int> vao , ra;
    vector <vector <int >> dsc ;
    for (int i =  1 ; i<= n ;i++){
        int c ;
        cin >> c;
        while (c--){
            int j;
            cin >> j;
            vao [j] ++ ; ra [i] ++;
            dsc.push_back ({i , j});
        }
    }
    if (t == 1) for (int i = 1; i <= n ; i++) cout << vao [i] << " " << ra [i]  << endl;
    else {
        cout << n << " " << dsc.size () << endl;
       for (int i =1 ; i<= n ;i++){
        for (auto x : dsc){
            int u = x[0] , v = x [1];
            if (u == i) cout << "1 ";
            else if (v == i) cout << "-1 ";
            else cout << "0 ";

        }
        cout << endl;
       }
    }

}
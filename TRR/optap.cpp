#include <bits/stdc++.h>
using namespace std ;
// neu hoi dsc thi vector <vector <Int>> 
// dske thi vector <set<int>>
// matran lien thuoc = cach tim dsc mỗi cạnh là 1 cột  
// tu dsk sang dsc thi dung set <vector<int>> dsc.insert (min , max) in ra cạnh
// từ dsk sang dsc in ra ma trận thì dùng set <pair <int,int>> 
// + = ra , - = vao , cột là ra , hàng là vào 

// mảng parent dùng để truy viết parent [105] = {0}

int n  ;
int a[105][105];
bool vs [105];
set <int> adj;
void dfs (int u , int ban){
   vs[u] = true; 
   for (int x = 1 ; x <= n ; x++){
        if (!vs[x] && ban != x && a[u][x]){
            dfs (x , ban);
        }
   }
}
int demtplt (int ban){
    memset (vs, false , sizeof (vs));
    int cnt = 0;
    for (int i =1;  i<= n ; i++){
        if (i != ban && !vs[i]){
            cnt ++;
            dfs (i , ban);
        }
    }
    return cnt;
}
int main (){
    cin >> n;
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            cin >> a[i][j];
        }
    }
    vector <int> res;
    int bandau = demtplt (0);
    for (int i = 1; i<= n ;i++){
        int saukhixoa = demtplt (i);
        if (saukhixoa > bandau) {
            res.push_back(i);
        }
    }
    cout << res.size () << endl;
    for (auto x : res ){
        cout << x << " ";
    }

}

#include <bits/stdc++.h>
using namespace std;

int n , st;
int a [105][105] = {};
bool vs [105] = {};
vector <pair<int,int>> adj [105];
/* thuật toán prim bắt đầu từ s mỗi bước chọn cạnh có trọng số min nối từ tập đỉnh chưa
chọn lặp lại cho đủ n - 1 cạnh
*/ 
void prim (){
    vector <vector <int>> res;
    int d = 0;
    vs[st] = true;
    while (res.size () < n -1){
        int nho = 1e9 , x , y;
        for (int i = 1 ; i<= n ; i++ ){
            if (vs[i]){
                for (pair <int,int> p : adj[i]){
                    int j = p.first , w = p.second;
                    if (!vs[j] && w < nho){
                        nho = w;
                        x = i , y = j;
                    }
                }
            }
        }
        res.push_back({min (x,y) , max (x , y),nho});
        d += nho;
        vs[y] = true;
    }
    cout << d << endl;
    for (auto v : res) cout << v[0] << " " << v[1] << " " << a[v[0]][v[1]] << endl;
}
int main (){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> st;
    for (int i = 1;  i<= n ;i++){
        for (int j = 1;  j <=n ; j++){
            int va; cin >> va;
            if (va != 10000 && i != j){
                a[i][j] = va;
                adj[i].push_back ({j,va});
                adj[j].push_back ({i , va});
            }
        }
    }
    prim ();
}
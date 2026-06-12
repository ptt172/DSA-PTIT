#include <bits/stdc++.h>
using namespace std ;
// neu hoi dsc thi vector <vector <Int>> 
// dske thi vector <set<int>>
// matran lien thuoc = cach tim dsc mỗi cạnh là 1 cột  
// tu dsk sang dsc thi dung set <vector<int>> dsc.insert (min , max) in ra cạnh
// từ dsk sang dsc in ra ma trận thì dùng set <pair <int,int>> 
// + = ra , - = vao , cột là ra , hàng là vào 

// mảng parent dùng để truy viết parent [105] = {0}

int n , m , d ;
int parent [105];
struct ed {
    int u , v , w;
};
vector <ed> T, V;
int cmp (ed a , ed b){
    if (a.w == b.w) {
        if (a.u == b.u){
            return a.v < b.v;
        }
        return a.u < b.u;
    }
    return a.w < b.w;
}
int Find (int u ){
    if (parent [u] == u) return u;
    return parent [u] = Find (parent [u]);

}
int Union (int u , int v){
    u = Find (u);
    v = Find (v);
    if (u == v) return false;
    parent [v] = u;
    return  true;
}
void kruskal (){
    d =  0;
    T.clear ();
    sort (V.begin () , V.end() , cmp);
    for (int i = 1; i<= n ;i++){
        parent[i] = i;
    }
    for (ed e : V){
        if (Union (e.u , e.v)){
            d+= e.w;
            T.push_back (e);
            if (T.size () == n-1) break;
        }
    }
}
int main (){
    cin >> n >> m;
    V.clear () ; T.clear();
    for (int i = 0 ; i< m ; i++){
        ed e;
        cin >>e .u >> e.v >> e.w ;
        V.push_back (e);
    }
    kruskal ();
    cout <<d << endl;
    for (int i = 0 ; i< T.size () ; i++){
       cout << T[i].u << " " << T[i].v <<  " " << T[i].w << endl;
    }
}


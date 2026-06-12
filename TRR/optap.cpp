#include <bits/stdc++.h>
using namespace std ;
// neu hoi dsc thi vector <vector <Int>> 
// dske thi vector <set<int>>
// matran lien thuoc = cach tim dsc mỗi cạnh là 1 cột  
// tu dsk sang dsc thi dung set <vector<int>> dsc.insert (min , max) in ra cạnh
// từ dsk sang dsc in ra ma trận thì dùng set <pair <int,int>> 
// + = ra , - = vao , cột là ra , hàng là vào 

// mảng parent dùng để truy viết parent [105] = {0}

int n, d, m;
struct Edge{
  int u;
  int v;
  int w;
};
vector<Edge> V, T;
int cmp(Edge e1, Edge e2) {
	if (e1.w == e2.w) {
		if (e1.u == e2.u) return e1.v < e2.v;
		return e1.u < e2.u;
	}
    return e1.w < e2.w;
}
int parent [105];
int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v) return false;

    parent[v] = u;
    return true;
}

void Kruskal() {
    d = 0;
    T.clear();

    sort(V.begin(), V.end(), cmp);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (Edge e : V) {
        if (Union(e.u, e.v)) {
            T.push_back(e);
            d += e.w;

            if (T.size() == n - 1)
                break;
        }
    }
}

int main() {
    
	V.clear(); T.clear();
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
      Edge e;
      cin >> e.u >> e.v >> e.w;
      V.push_back(e);
    }
    Kruskal();
    cout << d << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].u << " " << T[i].v <<  " " << T[i].w << endl;
    }

}
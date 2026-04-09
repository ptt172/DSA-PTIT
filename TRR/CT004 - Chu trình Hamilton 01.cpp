#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> a (105 , vector <int> (105));
vector <set <int>> ke (105);
vector <vector <int>> res;
vector <int > c;
vector <bool> vs (105,false);
int v , u;
void hamilton (int d){
    for (int j = 1;  j<= v ; j ++){
        if (!vs[j] && a[c[d - 1]][j]){
            vs[j] = true;
            c.push_back (j);
            if (d == v + 1){
                if (c[1] == c[d]) res.push_back (c);
            }
            else if (d <= v) hamilton (d + 1);
            c.pop_back ();
            vs[j] = false;
        }
    }
}
        
int main (){
    cin >> v >> u;
    for (int i =1 ; i  <= v ; i ++){
        for (int j = 1;  j <= v ; j++){
            cin >> a[i][j];
        }
    }
    c.push_back (0);
    c.push_back (u);
    hamilton (2);
    if (res.size () == 0) cout << "0 " << endl;
    else {
        cout << res.size () << endl;
        for (auto x : res){
            for (int i = 1;  i < x.size () ; i++){
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }
}
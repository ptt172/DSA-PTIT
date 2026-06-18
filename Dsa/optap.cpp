#include <bits/stdc++.h>
using namespace std;

int t, n, x;
vector<int> a, cur;
vector<vector<int>> res;

void ql(int i, int sum) {
    if (sum == x) {
        res.push_back(cur);
        return;
    }
    if (sum > x) return;
    for (int j = i; j < n; j++) {
        cur.push_back(a[j]);
        ql(j, sum + a[j]);
        cur.pop_back();
    }
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> x;

        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        cur.clear();
        res.clear();

        ql(0, 0);

        if (res.empty()) {
            cout << -1 << '\n';
        } else {
            for (auto v : res) {
                cout << "[";
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i != v.size() - 1) cout << " ";
                }
                cout << "] ";
            } 
            cout << endl;
            cout << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, u;
int a[105][105];
bool vs[105];
int X[105];
int cnt = 0;

void Hamilton(int i) {
    for (int v = 1; v <= n; v++) {
        if (!vs[v] && a[X[i - 1]][v]) {
            X[i] = v;
            vs[v] = true;

            if (i == n) {
                if (a[X[n]][u]) {
                    cnt++;

                    for (int j = 1; j <= n; j++) {
                        cout << X[j] << " ";
                    }
                    cout << u << endl;
                }
            } 
            else {
                Hamilton(i + 1);
            }

            vs[v] = false;
        }
    }
}

int main() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> n >> u;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    X[1] = u;
    vs[u] = true;

    Hamilton(2);

    if (cnt == 0) {
        cout << 0;
    } 
    else {
        cout << cnt;
    }

    return 0;
}
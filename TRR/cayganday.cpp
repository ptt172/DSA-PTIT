#include <bits/stdc++.h>
using namespace std;

int n , a[100005];
void inorder (int i){   
    if (i >= n) return;
    inorder (2*i + 1);
    cout << a[i] << " ";
    inorder (2*i + 2);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 0 ; i<n ; i++) cin >> a[i];
        inorder (0);
        cout << endl;
    }

    return 0;
}
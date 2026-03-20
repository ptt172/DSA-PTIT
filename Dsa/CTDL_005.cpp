#include <bits/stdc++.h>
using namespace std;
int main (){
	int n;
	cin >> n;
	int a[n];
	for (int &x : a) cin >> x;
	int m ;
	cin >> m;
	for (int i = 0 ;i<n;i++) {
		if (a[i] != m) cout << a[i] << " ";
	}
	cout << endl;
}

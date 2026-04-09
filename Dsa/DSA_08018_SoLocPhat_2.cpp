#include <bits/stdc++.h>
using namespace std;

int main (){
	int t;
	cin >> t;
	while (t--){
		int n ;
		cin >> n;
		vector <string> res;
		queue <string> q;
		q.push ("6");
		q.push ("8");
		while (!q.empty()){
			string s = q.front ();
			q.pop ();
			if (s.size () > n) continue;
			res.push_back (s);
			q.push (s + "6");
			q.push (s + "8");
		}
		cout  << res.size () << endl;
		for (auto x : res) cout << x << " ";
		cout << endl;
	}
	}
    
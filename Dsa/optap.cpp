#include <bits/stdc++.h>
using namespace std;


struct tree {
    int val;
    tree *right , *left ;
    tree (int x){
        val = x;
        right = left = NULL;
    }
};
tree *build (vector <string> &a , int i){
    if (i >= a.size () || a[i] == "N") return NULL;
    tree * root = new tree (stoi(a[i]));
    root -> left = build (a , 2 * i + 1);
    root -> right = build (a , 2 * i + 2);
    return root;
}
void inpos (tree *root){
    if (root == NULL) return ;
    inpos (root -> right);
    cout << root-> val << " ";
    inpos (root -> left);
}
int main (){
    int t;
    cin >> t;
    cin.ignore ();
    while (t--){
        string s;
        getline (cin , s);
        stringstream ss (s);
        string x;
        vector  <string>a;
        while (ss >> x){
            a.push_back (x);
        }
        tree *root = build (a , 0);
        inpos (root);
        cout << endl;
    }
}
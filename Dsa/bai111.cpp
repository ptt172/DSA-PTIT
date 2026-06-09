#include <bits/stdc++.h>
using namespace std;
struct tree {
    int data;
    tree *left, *right;
    tree (int x) {
        data = x;
        left = right = NULL;
    }
};
tree* inserttree(tree* root, int x) {
    if (root == NULL) return new tree(x);
    if (x < root->data)
        root-> right = inserttree(root->right, x);
    else
        root->left = inserttree(root->left, x);
    return root;
}
void NRL(tree* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    NRL(root->left);
    NRL(root->right);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        tree* root = NULL;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            root = inserttree(root, x);
        }
        NRL(root);
        cout << endl;
    }
    return 0;
}
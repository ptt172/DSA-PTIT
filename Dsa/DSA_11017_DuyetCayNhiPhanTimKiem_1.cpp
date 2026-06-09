#include <bits/stdc++.h>
using namespace std;
int n, preor[1005];
struct Tree {
    int value;
    Tree* left;
    Tree* right;
};
Tree* newNode(int val) {
    Tree* temp = new Tree;
    temp->value = val;
    temp->left = temp->right = NULL;
    return temp;
}

Tree* buildTree(int minVal, int maxVal, int &preIndex) {
    if (preIndex >= n) return NULL;
    int val = preor[preIndex];
    if (val < minVal || val > maxVal)
        return NULL;
    Tree* root = newNode(val);
    preIndex++;
    root->left = buildTree(minVal, val - 1, preIndex);
    root->right = buildTree(val + 1, maxVal, preIndex);
    return root;
}

Tree* buildTreeWrap() {
    int preIndex = 0;
    return buildTree(INT_MIN, INT_MAX, preIndex);
}
void printPost(Tree* root) {
    if (root == NULL) return;
    printPost(root->left);
    printPost(root->right);
    cout << root->value << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
        cin >> preor[i];
        Tree* root = buildTreeWrap();
        printPost(root);
        cout << endl;
    }
    return 0;
}
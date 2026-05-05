#include <bits/stdc++.h>
using namespace std;
int n , preor [5005];
struct tree {
    int value;
    tree *left , * right ;
};
tree *newnode (int x){
    tree *tmp = new tree;
    tmp -> left = tmp -> right = NULL;
    tmp -> value = x;
    return tmp;
}
tree *buildtree (int nho , int lon , int &pre){
    if (pre >= n ) return NULL;
    int val = preor [pre];
    if (val < nho || val > lon) return NULL;
    tree *tmp = newnode (val);
    pre ++;
    tmp -> left = buildtree (nho , val , pre);
    tmp -> right = buildtree (val , lon , pre);
    return tmp;
}
tree *buildtreewrap (){
    int pre = 0;
    return buildtree (INT_MIN , INT_MAX , pre);
}
void inpos (tree * tmp){
    if (tmp == NULL) return;
        cout << tmp -> value << " ";
        inpos (tmp -> left);
        inpos (tmp -> right);
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0 ; i<n ; i++) cin >> preor [i];
        tree *root = buildtreewrap ();
        inpos (root);
        cout << endl;
    }
    return 0;
}
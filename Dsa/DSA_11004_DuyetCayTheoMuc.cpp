#include <bits/stdc++.h>
using namespace std;
struct tree {
    int data ;
    tree * right , *left ;
    tree  (int x){
        data = x;
        right = left = NULL;
    }
};
void leveloder (tree * root){
    queue <tree * > q;
    q .push (root);
    while (!q.empty()){
        tree *t = q.front (); q.pop();
        cout << t -> data << " ";
        if (t -> left != NULL) q .push (t -> left);
        if (t -> right != NULL) q .push (t -> right);
    }
}
void insert (tree * root , int n1 , int n2 , char c) {
    if (root == NULL) return ;
    if (root -> data == n1){
        if (c == 'L') root -> left = new tree (n2);
        else root -> right = new tree (n2);
    }
    else {
        insert (root -> left , n1 , n2 , c);
        insert (root -> right , n1 , n2 , c);
    }
}
int main (){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        tree *root = NULL;
        for (int i = 0 ; i < n ; i++){
            int n1 , n2; char c;
            cin >> n1 >> n2 >> c;
            if (root == NULL) root = new tree (n1);
            insert (root , n1 , n2 , c);
        }
        leveloder (root);
        cout << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
struct tree {
    int data ;
    tree * right , * left ;
    tree (int x ){
        data = x;
        right = left = NULL;
    }
};
void insert (tree *root , int n1 , int n2 , char c){
    if (root == NULL) return ;
    if (root -> data == n1){
        if (c == 'L') root -> left = new tree (n2 );
        else root -> right = new tree (n2);
    }
    else {
        insert (root -> left , n1 , n2 , c);
        insert (root -> right , n1 , n2 , c);
    }
}
tree * build (int n){
    tree * root = NULL;
    while (n --){
        int n1 , n2 ;char c;
        cin >> n1 >> n2 >> c;
        if (root == NULL){
            root = new tree (n1);
            if (c =='L') root -> left = new tree (n2);
            else root -> right = new tree (n2);
        }
        else insert (root , n1 , n2 , c);
    }
    return root;
}
bool same (tree * root1 , tree * root2){
    if (root1 == NULL && root2 == NULL ) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return  (root1->data == root2->data) 
    && same (root1 -> left , root2 -> left) && same (root1 -> right , root2 -> right);
}
int main (){
    int t , n1 , n2;
    cin >> t;
    while (t--){
        cin >> n1 ;
        tree * root1 = build (n1);
        cin >> n2 ;
        tree * root2 = build (n2);
        cout << (same (root1 , root2) ? 1 : 0) << endl;
    }
}
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
bool nhiphan (tree *root){
    if (root == NULL) return true;
    if (root -> left == NULL && root -> right == NULL) return true;
    if (root -> left != NULL && root -> right != NULL) 
    return nhiphan (root -> left) && nhiphan (root -> right);
    return false;
}
int main (){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        tree *root = NULL;
        while (n--){
            int n1, n2; char c;
            cin >> n1 >> n2 >> c;
            if (root == NULL){
                root = new tree (n1);
                if (c == 'L') root -> left = new tree (n2);
                else root -> right = new tree (n2);
            }
            else insert (root , n1 , n2 , c);
        }
        cout << (nhiphan (root) ? 1 : 0) << endl;
    }
}
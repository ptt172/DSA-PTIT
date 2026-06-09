#include <bits/stdc++.h>
using namespace std;
struct tree {
    int data;
    tree *right , *left ;
    tree (int x) {
        data = x;
        right = left = NULL;
    }
};
void insert (tree *root , int n1 , int n2 , char c){
    if (root == NULL) return;
    if (root -> data == n1){
        if (c == 'L') root -> left = new tree (n2);
        else root -> right = new tree (n2);
    }
    else {
        insert (root -> left , n1 , n2 , c);
        insert (root -> right , n1 , n2 , c);
    }
}// o (n ^ 2)
void xoanoc (tree * root){
    if (root == NULL) return ;
    stack <tree *> s1 , s2;
    s1.push (root);
    while (!s1.empty () || !s2.empty ()){
        while (!s1.empty ()){
            tree * t = s1.top () ; s1.pop ();
            cout << t -> data << " ";
            if (t -> right ) s2.push (t -> right);
            if (t -> left ) s2.push (t -> left);
        }
        while (!s2.empty ()){
            tree *t = s2.top () ;s2.pop ();
            cout << t -> data << " ";
            if (t -> left ) s1.push (t -> left);
            if (t -> right ) s1.push (t -> right);
        }
    }
}

int main(){
    int t , n;
    cin >> t;
    while (t--){
        cin >> n;
        tree *root = NULL;
        while (n --){
            int n1 , n2 ; char c;
            cin >> n1 >> n2 >> c;
            if (root == NULL) {root = new tree (n1);
            if (c == 'L') root -> left = new tree (n2);
            else root -> right = new tree (n2);
            }
            else insert (root , n1 , n2 , c);
        }
        xoanoc (root);
        cout << endl;
    }
    return 0;
}
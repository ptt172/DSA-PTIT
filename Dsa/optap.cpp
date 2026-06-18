#include <bits/stdc++.h>
using namespace std;

int n ;
struct tree {
    int val ;
    tree *left , *right ;
};

tree *newnode (int x){
    tree *tmp = new tree ;
    tmp -> val = x;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

tree *build (vector <int> ino , vector <int> level){
    if (ino.size () == 0) return NULL;
    tree *root = newnode (level [0]);
    vector <int> trai , phai , trail , phail;
    int pos = 0;
    while (ino[pos] != root -> val){
        pos ++;
    }
    for (int i = 0 ; i< pos ; i++){
        trai.push_back (ino[i]);
    }
    for (int i = pos + 1 ; i < ino.size () ; i++){
        phai.push_back (ino[i]);
    }
    for (int x : level){
        if (x == root -> val) continue;
        if (find (trai.begin () , trai.end () , x) != trai.end()){
            trail.push_back (x);
        }
        else phail.push_back (x);
    }
    root -> left = build (trai , trail);
    root -> right = build (phai , phail);
    return root;
}
void inpos (tree *root){
    if (root == NULL) return;
    inpos (root -> left);
    inpos (root -> right);
    cout << root -> val << " ";
}
int main (){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        vector <int> ino (n) , level (n);
        for (int i = 0 ; i< n ;i++) cin >> ino [i];
        for (int i = 0 ; i< n ; i++) cin >> level [i];
        tree *root = build (ino , level);
        inpos (root);
        cout << endl;
    }
}


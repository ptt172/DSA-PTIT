#include <bits/stdc++.h>
using namespace std;
int n , innor[1005] , levelor [1005];
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
tree *buildtree (int bd , int kt, map <int,int> mp){
    if (bd > kt ) return NULL;
    int index = bd;
    for (int j = bd + 1 ; j <= kt ; j++){
        if ( mp [innor [j]] < mp [innor [index]]) index = j;
    }
    tree *tmp = newnode (innor [index]);
    tmp -> left = buildtree (bd , index - 1 , mp);
    tmp -> right = buildtree (index + 1 , kt  , mp);
    return tmp;
}
tree *buildtreewrap (){
    map <int, int> mp;
    for (int i = 0 ; i < n ; i++){
        mp [levelor [i]] = i;
    }
    return buildtree (0 , n - 1 , mp);
}
void inpos (tree * tmp){
    if (tmp != NULL){
        inpos (tmp -> left);
        inpos (tmp -> right);
        cout << tmp -> value << " ";
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >>n;
        for (int i = 0 ; i < n ; i++) cin >> innor [i];
        for (int i = 0 ; i < n ; i++) cin >> levelor [i];
        tree *root = buildtreewrap ();
        inpos (root);
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n , innor[1005] , preor [1005];
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
tree *buildtree (int bd , int kt , int &pre ,map <int,int> &mp){
    if (bd > kt ) return NULL;
    tree *tmp = newnode (preor [pre++]);
    if (bd == kt) return tmp;
    int index = mp [tmp -> value];
    tmp -> left = buildtree (bd , index - 1 , pre , mp);
    tmp -> right = buildtree (index + 1 , kt , pre , mp);
    return tmp;
}
tree *buildtreewrap (){
    map <int, int> mp;
    for (int i = 0 ; i < n ; i++){
        mp [innor [i]] = i;
    }
    int preindex = 0;
    return buildtree (0 , n - 1 , preindex , mp);
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
        for (int i = 0 ; i < n ; i++) cin >> preor [i];
        tree *root = buildtreewrap ();
        inpos (root);
        cout << endl;
    }
    return 0;
}
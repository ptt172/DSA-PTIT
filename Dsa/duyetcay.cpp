#include<bits/stdc++.h>
using namespace std;

int n;
struct tree{
	int value;
	tree *left, *right;
};
tree *newnode(int val){
	tree *tmp=new tree;
	tmp->left=tmp->right=NULL;
	tmp->value=val;
	return tmp;
}

tree *build(){
	map<int,tree*> mp;
	tree *root=NULL;
	while(n--){
		int a,b;
		char x; cin >> a >> b >> x;
		tree *cha=newnode(a);
		if(mp.find(a)==mp.end()){
			mp[a]=cha;
			if(root==NULL) root=cha;
		}
		else cha=mp[a];
		tree *con=newnode(b);
		if(x=='L') cha->left=con;
		else if(x=='R') cha->right=con;
		mp[b]=con;
	}
	return root;
}
void buildwrap(tree *root){
	if(root==NULL) return;
	queue<tree*> q;
	stack<int> st;
	q.push(root);
	while(!q.empty()){
		tree *t=q.front();
		st.push(t->value);
		q.pop();
		if(t->right!=NULL) q.push(t->right);
		if(t->left!=NULL) q.push(t->left);
		
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}
void pos(tree *t){
	if(t==NULL) return;
	if(t!=NULL){
		cout << t->value << " ";
		pos(t->left);
		pos(t->right);
		
	}
}
void init(){
	cin >> n;
	tree *root=build();
	buildwrap(root);
	cout << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		init();
	}
}
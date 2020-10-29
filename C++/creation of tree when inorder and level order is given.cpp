//create a tree when levelorder and inorder is given
#include <bits/stdc++.h>
using namespace std;

class Node {
	node *left, *right;
	int data;
}*root=nullptr;

Node *NewNode(int data) {
	Node *nn = new Node;
	nn->left = nullptr;
	nn->right = nullptr;
	nn->data = data;
	return nn;
}

void Inorder(Node *root) {
	if(root == nullptr)
	return;
	InOrder(root->left);
	cout<<root->data;
	InOrder(root->right);
}

Node* CreateTree(int *inorder, int start, int last, unordered_map<int, int> map) {
	if(start  > last)
		return nullptr;
	int index = start;
	for(int j=start+1; j<=last; j++) {
		if(map[inorder[j]]<map[inorder[index]])
		index = j;
	}	
	Node* root = NewNode(inorder[index]);
	root->left = CreateNode(inorder,start,index-1,map);
	root->rigth = CreateNode(inorder,start,index-1,map);
}

Node* BuildTree(int *inorder, int *levelorder, int n) {
	unordered_map<int, int> map;
	for(int i=0; i<n; i++) {
		map[levelorder[i]] = i;
	}
	return CreateTree(inorder, 0, n-1, map);
}

int main()
{
	int inorder[] = {4,2,5,1,6,3,7};
	int levelorder[] = {1,2,3,4,5,6,7};
	
	int n = sizeof(inorder)/sizeof(inorder[0]);
	BuildTree(inorder, levelorder, n);
}


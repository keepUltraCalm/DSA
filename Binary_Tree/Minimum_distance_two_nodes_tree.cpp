//Find the minimum distance between two nodes in a binary tree
//distance meaning number of edges
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

Node* LCA(Node *root, int n1, int n2) {
	if (root == NULL)
		return NULL;
	if (root->data == n1 || root->data == n2)
		return root;
	Node *lca1 = LCA(root->left, n1, n2);
	Node *lca2 = LCA(root->right, n1, n2);
	if (lca1 != NULL && lca2 != NULL)
		return root;
	if (lca1 != NULL)
		return lca1;
	else
		return lca2;
}

int distance(Node *root, int n) {
	if (root == NULL)
		return -1;
	int dis = -1;
	if ((root->data == n) ||
	        (dis = distance(root->left, n)) >= 0 ||
	        (dis = distance(root->right, n)) >= 0)
		return dis + 1;//if mila to left aur right ki vje se 1 add kiya

	return dis;//else to return dis which is -1
}

int final_dis(Node *lca, int n1, int n2) {
	// if (lcs == NULL)
	// 	return -1;pakka we will get, so don't write
	int d1 = distance(lca, n1);
	int d2 = distance(lca, n2);
	return d1 + d2;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(40);
	root->right->right = new Node(50);

	int n1 = 10, n2 = 50;
	Node *lca = LCA(root, n1, n2);
	int res = final_dis(lca, n1, n2);
	cout << res;

	return 0;
}


//topics cleared with this q

/*
1. how to find LCA
2. how to find distance between root and given node
3. how to find min distance b/w two nodes in binary tree
*/

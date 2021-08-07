
ITERATIVE LEVEL ORDER TRAVERSAL BINARY TREE
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

void bfs(Node *root) {
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (q.empty() == false) {
		int count = q.size();
		for (int i = 1; i <= count; i++) {
			Node *u = q.front();
			q.pop();
			cout << u->data << " ";
			if (u->left != NULL)
				q.push(u->left);
			if (u->right != NULL)
				q.push(u->right);
		}
		cout << '\n';
	}
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	bfs(root);
	return 0;
}

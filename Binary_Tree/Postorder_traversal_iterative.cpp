//postorder iterative


#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int data;
	Node* right;
	Node *left;
	Node(int data) {
		this->data = data;
		right = left = NULL;
	}
};

void iterative_postorder(Node *root) {
	stack<Node*> s;
	while (root != NULL) {
		if (root->right != NULL)
			s.push(root->right);
		s.push(root);
		root = root->left;
	}
	while (!s.empty()) {
		if (root != NULL) {
			while (root != NULL) {
				if (root->right != NULL)
					s.push(root->right);
				s.push(root);
				root = root->left;
			}
		} else {
			root = s.top();
			s.pop();
			if (!s.empty() && root->right != NULL && root->right == s.top()) {
				Node *temp = s.top();
				s.pop();
				s.push(root);
				root = temp;
			} else {
				cout << root->data << " ";
				root = NULL;
			}
		}
	}
}


int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	iterative_postorder(root);
	return 0;
}

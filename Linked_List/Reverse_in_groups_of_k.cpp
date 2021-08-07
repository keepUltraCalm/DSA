#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

Node *reverseK(Node *head, int k) {
	Node *curr = head, *prevFirst = NULL;
	bool firstPass = true;
	while (curr != NULL) {
		int count = 0;
		Node *prev = NULL, *first = curr;
		while (curr != NULL && count < k) {
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			++count;
		}
		if (firstPass) {
			head = prev;
			firstPass = false;
		} else {
			prevFirst->next = prev;
		}
		prevFirst = first;
		//previous part ka original first
	}
	return head;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	int y;
	cin >> y;
	Node *head = new Node(y);
	Node *curr = head;
	Node *curr2 = head;
	for (int i = 1; i <= n - 1; i++) {
		int x;
		cin >> x;
		curr->next = new Node(x);
		curr = curr->next;
	}

	while (curr2 != NULL) {
		cout << curr2->data << " ";
		curr2 = curr2->next;
	}
	cout << '\n';
	cout << '\n';

	Node *ans = reverseK(head, k);
	while (ans != NULL) {
		cout << ans->data << " ";
		ans = ans->next;
	}
	cout << '\n';
	return 0;
}


/*
10 3
1 2 3 4 5 6 7 8 9 10

O/P
1 2 3 4 5 6 7 8 9 10

3 2 1 6 5 4 9 8 7 10

*/


/*
Concepts:
Linked list creation using input
Linked list traversal
Reverse in groups of k
*/

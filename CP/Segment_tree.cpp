//SEGMENT TREE CREATION

#include <bits/stdc++.h>
using namespace std;

void buildTree(int arr[], int tree[], int start, int end, int treeNode) {
	if (end == start) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void update(int arr[], int tree[], int start, int end, int treeNode, int indx, int value) {
	if (start == end) {
		arr[indx] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start + end) / 2;
	if (indx > mid) {
		update(arr, tree, mid + 1, end, 2 * treeNode + 1, indx, value);
	} else {
		update(arr, tree, start, mid, 2 * treeNode, indx, value);
	}
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int tree[], int start, int end, int treeNode, int left, int right) {
	if (start > right || end < left)
		return 0;
	else if (start >= left && end <= right)
		return tree[treeNode];
	else {
		int mid = (start + end) / 2;
		int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
		int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
		return ans1 + ans2;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int tree[2 * n];
	tree[0] = 0;
	int treeNode = 1;
	int start = 0, end = n - 1;
	buildTree(arr, tree, start, end, treeNode);
	int indx = 2, value = 10;
	update(arr, tree, start, end, treeNode, indx, value);

	for (auto x : tree)
		cout << x << " ";
	cout << '\n';

	cout << query(tree, 0, 4, 1, 2, 4);
	return 0;
}

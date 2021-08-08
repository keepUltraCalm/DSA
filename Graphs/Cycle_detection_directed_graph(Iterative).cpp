#include <bits/stdc++.h>
using namespace std;

void create_graph(vector<int> adj[], int u, int v, int arr[]) {
	adj[u].push_back(v);
	++arr[v];
}

int is_directed(vector<int> adj[], int arr[], int vtx) {
	int count = 0;
	queue<int> q;
	for (int i = 0; i < vtx; i++) {
		if (arr[i] == 0)
			q.push(i);
	}
	while (q.empty() == false) {
		int u = q.front();
		q.pop();
		for (auto x : adj[u]) {
			--arr[x];
			if (arr[x] == 0)
				q.push(x);
		}
		++count;
	}
	return count;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int vtx = 5;
	vector<int> adj[vtx];
	int arr[vtx] = {0};

	create_graph(adj, 0, 1, arr);
	create_graph(adj, 1, 2, arr);
	create_graph(adj, 2, 3, arr);
	create_graph(adj, 3, 1, arr);
	create_graph(adj, 4, 1, arr);

	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < vtx; i++)
		cout << arr[i] << " ";
	cout << '\n';

	cout << is_directed(adj, arr, vtx);

	return 0;
}


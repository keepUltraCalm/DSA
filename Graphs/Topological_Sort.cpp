//TOPOLOGICAL SORT: KAHN'S BFS ALGO

#include <bits/stdc++.h>
using namespace std;

void create_graph(vector<int> adj[], int u, int v, vector<int> &dg) {
	adj[u].push_back(v);
	++dg[v];
}

void topo_sort(vector<int> adj[], vector<int> dg, int vtx) {
	queue<int> q;
	for (int i = 0; i < vtx; i++) {
		if (dg[i] == 0)
			q.push(i);
	}
	while (q.empty() == false) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (auto v : adj[u]) {
			--dg[v];
			if (dg[v] == 0)
				q.push(v);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int vtx = 5;
	vector<int> adj[vtx];
	vector<int> dg(vtx, 0);
	create_graph(adj, 0, 2, dg);
	create_graph(adj, 0, 3, dg);
	create_graph(adj, 2, 3, dg);
	create_graph(adj, 1, 3, dg);
	create_graph(adj, 1, 4, dg);

	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}

	for (auto x : dg)
		cout << x << " ";
	cout << '\n';

	topo_sort(adj, dg, vtx);

	return 0;
}

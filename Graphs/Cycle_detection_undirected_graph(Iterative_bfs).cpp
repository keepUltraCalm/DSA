
//CYCLE DETECTION UNDIRECTED GRAPH ITERATIVE BFS
#include <bits/stdc++.h>
using namespace std;

void create_graph(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool BFS(vector<int> adj[], int s, bool visited[], int vtx) {
	int parent[vtx];
	for (int i = 0; i < vtx; i++)
		parent[i] = -1;
	visited[s] = true;
	queue<int> q;
	q.push(s);
	while (q.empty() == false) {
		int u = q.front();
		q.pop();
		for (auto x : adj[u]) {
			if (visited[x] == false) {
				visited[x] = true;
				q.push(x);
				parent[x] = u;
				// if visited[x] is true and x is not parent of u
				//parent to phle hi true hoga u ka..ab adjaceny list mein 
				//vo bhi to aaega..to vo nhi lena h
			} else if (parent[u] != x) {
				return true;
			}
		}
	}
	return false;
}

bool bfs_r(vector<int> adj[], int vtx) {
	bool visited[vtx];
	for (int i = 0; i < vtx; i++)
		visited[i] = false;
	for (int i = 0; i < vtx; i++) {
		if (visited[i] == false) {
			//if again it comes means seperate graph
			//now check if this has cycle
			//agar prev mein hi mil gyi..to jaenge hi nhi
			if (BFS(adj, i, visited, vtx) == true)
				return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int vtx = 5;
	vector <int> adj[vtx];

	//graph 1
	create_graph(adj, 0, 1);
	//graph 2
	create_graph(adj, 2, 3);
	create_graph(adj, 2, 4);
	create_graph(adj, 3, 4);

	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}
	cout << '\n';

	bool res = bfs_r(adj, vtx);

	if (res)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

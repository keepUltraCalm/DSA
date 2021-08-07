//ITERATIVE BFS

#include <bits/stdc++.h>
using namespace std;

void create_graph(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(vector<int> adj[], int s, bool visited[]) {
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (q.empty() == false) {
		int u = q.front();
		cout << u << " ";
		q.pop();
		for (auto v : adj[u]) {
			if (visited[v] == false) {
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int BFS_dis(vector<int> adj[], int vtx) {
	int count = 0;
	bool visited[vtx];
	for (int i = 0; i < vtx; i++)
		visited[i] = false; //don't use for each loop for assign
	for (int i = 0; i < vtx; i++) {
		if (visited[i] == false) {
			count++;
			bfs(adj, i, visited);
		}
	}
	return count;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int vtx = 7;
	vector <int> adj[vtx];
	//graph 1
	create_graph(adj, 0, 1);
	create_graph(adj, 0, 2);
	create_graph(adj, 1, 3);
	create_graph(adj, 2, 3);
	//graph 2
	create_graph(adj, 4, 5);
	create_graph(adj, 4, 6);
	create_graph(adj, 5, 6);

	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}

	int ans = BFS_dis(adj, vtx);
	cout << '\n';
	cout << ans;

	return 0;
}


//bfs yaad rakho
//dfs mein q ka stack...front ka top

//bfs..hmesha   0 1 2 3 4 ese
//dfs hoga  0 se connected sabsa bada number phle..kyuki stack h

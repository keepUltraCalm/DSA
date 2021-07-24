
/*
    0---2  \
    |   |   4
    1---3  /

    graph

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000007;

void push_element(vector<int> adj[], int u, int v) {
	//cannot pass adj as reference
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFS(vector<int> adj[], int curr, bool visited[]) {
	visited[curr] = true;
	cout << curr << " ";
	for (auto x : adj[curr]) {
		if (visited[x] == false)
			DFS(adj, x, visited);
	}
}

void dfs(vector<int>adj[], int vtx, int curr) {
	bool visited[vtx] = {0};
	DFS(adj, curr, visited);
}

int main() {
	cout << fixed;
	cout << setprecision(2);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int vtx = 5;
	vector<int> adj[vtx];
	//cannot use adj.size()
	push_element(adj, 0, 1);
	push_element(adj, 0, 2);
	push_element(adj, 1, 3);
	push_element(adj, 1, 4);
	push_element(adj, 2, 3);
	push_element(adj, 3, 4);

	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}
	cout << '\n';

	int cur = 0; //vertex is 0

	dfs(adj, vtx, cur);

	return 0;
}


/*

1 2 
0 3 4 
0 3 
1 2 4 
1 3 

0 1 3 2 4 

*/

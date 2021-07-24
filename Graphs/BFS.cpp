
#include <bits/stdc++.h>
using namespace std;

void push_element(vector<int> adj[], int u, int v) {
	//cannot pass adj as reference
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(vector<int> adj[], int vtx, int cur) {
	bool arr[vtx];
	for (int i = 0; i < vtx; i++)
		arr[i] = false;
	queue<int> q;
	arr[cur] = true;
	q.push(cur);
	while (q.empty() == false) {
		int p = q.front();
		q.pop();
		cout << p << " ";
		for (auto x : adj[p]) {
			if (arr[x] == false) {
				arr[x] = true;
				q.push(x);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int vtx = 5;
	vector<int> adj[vtx];
	//cannot use adj.size()
	push_element(adj, 0, 1);
	push_element(adj, 0, 2);
	push_element(adj, 1, 2);
	push_element(adj, 1, 3);
	push_element(adj, 2, 3);
	push_element(adj, 2, 4);
	push_element(adj, 3, 4);

	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}
	cout << '\n';

	int cur = 0; //vertex is 0

	bfs(adj, vtx, cur);

	return 0;
}


/*

1 2 
0 2 3 
0 1 3 4 
1 2 4 
2 3 

0 1 2 3 4 

*/

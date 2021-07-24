/*
GRAPH CREATION
*/

#include <bits/stdc++.h>
using namespace std;

void push_element(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> adj[5];
	push_element(adj, 0, 1);
	push_element(adj, 0, 2);
	push_element(adj, 1, 2);
	push_element(adj, 1, 3);
	push_element(adj, 2, 3);
	push_element(adj, 2, 4);
	push_element(adj, 3, 4);

//traversing the vector
	for (auto x : adj) {
		for (auto y : x)
			cout << y << " ";
		cout << '\n';
	}

	return 0;
}



/*

1 2 
0 2 3 
0 1 3 4 
1 2 4 
2 3 


*/

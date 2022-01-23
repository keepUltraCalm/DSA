#include <bits/stdc++.h>
using namespace std;

void push_item(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void prims(vector<pair<int, int>> adj[], int size, int source) {
    //traversing graph
    for (int i = 0; i < size; i++) {
        for (auto x : adj[i])
            cout << i << "," << x.first << "," << x.second << '\n';
    }
    cout << '\n';

    //prim's algo 😎
    int sum = 0;
    vector<bool> mst(size, false);
    vector<int> parent(size, -1);
    vector<int> key(size, INT_MAX);
    priority_queue<pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    key[source] = 0;
    sum += key[source];
    parent[source] = source;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (mst[u] == true)
            continue;

        mst[u] = true;
        sum += key[u]; //final value of u's weight is stored in key

        for (auto x : adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = x.first;
            int weight = x.second;

            // If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (mst[v] == false && weight < key[v])
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Print edges of MST using parent array
    cout << "Tree: " << '\n';
    for (int i = 0; i < size; i++) {
        cout << parent[i] << " - " << i << '\n';
    }
    cout << '\n';
    cout << "Everything visited!!" << '\n';
    for (int i = 0; i < size; i++) {
        cout << mst[i] << " ";
    }
    cout << "\n\n";
    cout << "Paths values: " << '\n';
    for (int i = 0; i < size; i++) {
        cout << key[i] << " ";
    }
    cout << "\n";
    cout << "Sum: " << sum;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int V = 4; //v is no. of vertices
    vector<pair<int, int>> adj[V];
    //in this algo..we need adjacency list
    push_item(adj, 0, 1, 5);
    push_item(adj, 0, 2, 8);
    push_item(adj, 1, 2, 10);
    push_item(adj, 1, 3, 15);
    push_item(adj, 2, 3, 20);

    int source = 0;//check different src will give same result

    prims(adj, V, source);

    return 0;
}

/*
Graph

            1
           /|\
        5 / | \ 15
         /  |  \
        0   |   3
         \  |10 /
       8  \ |  /
           \| / 20
            2

Time = O(ElogV)
Space = 3 array size V

*/

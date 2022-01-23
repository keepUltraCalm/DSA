#include <bits/stdc++.h>
using namespace std;

//creating a weighted, directed, acyclic graph
void create_graph(vector<pair<int, int>> adj[], int u, int v, int wt, vector<int> &in_dg) {
    adj[u].push_back({v, wt});
    ++in_dg[v];
}

queue<int> topological_sort(vector<pair<int, int>> adj[], vector<int> &in_dg, int V) {
    queue<int> q;
    queue<int> s;
    for (int i = 0; i < V; i++) {
        if (in_dg[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        s.push(u);
        for (auto x : adj[u]) {
            --in_dg[x.first];
            if (in_dg[x.first] == 0)
                q.push(x.first);
        }
    }
    return s;
}

void shortest_dis_DAG(vector<pair<int, int>> adj[], queue<int> &s, vector<int> &dis, int source) {
    dis[source] = 0;
    int INF = INT_MAX;
    while (!s.empty()) {
        int u = s.front();
        s.pop();
        if (dis[u] != INF) {
            for (auto y : adj[u]) {
                int v = y.first;
                //visited[v]=true;
                int wt = y.second;
                if (dis[v] > dis[u] + wt) {
                    dis[v] = dis[u] + wt;
                }
            }
        }
    }
    cout << "Distances from source " << source << " to all vertices are: " << "\n";
    for (auto x : dis)
        cout << x << " ";
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int V = 6; //no. of vertices
    vector<pair<int, int>> adj[V]; //adj-list
    vector<int> in_dg(V, 0); //in-degrees
    create_graph(adj, 0, 1, 2, in_dg);
    create_graph(adj, 0, 4, 1, in_dg);
    create_graph(adj, 1, 2, 3, in_dg);
    create_graph(adj, 2, 3, 6, in_dg);
    create_graph(adj, 4, 2, 2, in_dg);
    create_graph(adj, 4, 5, 4, in_dg);
    create_graph(adj, 5, 3, 1, in_dg);

    cout << "Adjacency List: " << "\n";
    for (int i = 0; i < V; i++) {
        for (auto x : adj[i])
            cout << x.first << "," << x.second << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "in-degree's: " << "\n";
    for (auto x : in_dg)
        cout << x << " ";
    cout << "\n\n";

    queue<int> s = topological_sort(adj, in_dg, V);
    // cout << "Toplogical Sort of Graph: " << "\n";
    // for (auto x : s)
    //     cout << x << " ";
    // cout << "\n\n";

    vector<int> dis(V, INT_MAX);
    int source = 4;
    shortest_dis_DAG(adj, s, dis, source);

    return 0;
}


//time : O(2*(V+E))

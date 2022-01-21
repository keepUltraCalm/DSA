#include <bits/stdc++.h>
using namespace std;

//graph node..doesn't need pointer
struct Node {
    int u;
    int v;
    int wgt;
    Node(int first, int second, int weight) {
        u = first;
        v = second;
        wgt = weight;
    }
};

//creating a directed graph
void push_item(vector<Node> &adj, int u, int v, int wt) {
    adj.push_back(Node(u, v, wt));
}

void bellman_ford(vector<Node> adj, int size, int source) {
    //traversing graph
    for (auto x : adj)
        cout << x.u << "," << x.v << "," << x.wgt << '\n';
    cout << '\n';

//bellman_ford😎
    vector<int> dis(size, INT_MAX);
    dis[source] = 0;
    for (int i = 1; i <= size - 1; i++) {
        for (auto x : adj) {
            if (dis[x.u] + x.wgt < dis[x.v])
                dis[x.v] = dis[x.u] + x.wgt;
        }
    }
    bool checker = false;
    for (auto x : adj) {
        if (dis[x.u] + x.wgt < dis[x.v]) {
            checker = true;
            break;
        }
    }
    if (!checker) {
        cout << "Shortest distances from source " << source << " to all nodes are: ";
        cout << '\n';
        for (auto x : dis)
            cout << x << " ";
    } else {
        cout << "Negative weight-cycle detected!!";
    }
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int V = 4; //v is no. of vertices
    vector<Node> adj;
    push_item(adj, 0, 1, 1);
    push_item(adj, 1, 2, -3);
    push_item(adj, 1, 3, 2);
    push_item(adj, 2, 0, 1);//change this weight to see changes..if weight-cycle is 0..still algo works
    //order matters..first node connected from source should be relaxed..so add in vector acc.ly
    push_item(adj, 2, 3, 3);

    int source = 0;

    bellman_ford(adj, V, source);

    return 0;
}

/*
Graph

              1
           1↗ ↓ ↘2
          ↗   ↓   ↘
         0    ↓-3   3
          ↘   ↓    ↗
           1 ↘ 2 ↗3

           So the time complexity: O((V-1)*E)...relaxing V-1 times..and for E edges
           space O(V) -> distance array
           Dijkstra's is way better..but this algo helps in detecting -ve weight cycles

           In case of complete graph.. number of edges goes till n(n-1)
           so this will become a cubic algo

*/

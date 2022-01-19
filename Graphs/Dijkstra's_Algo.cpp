#include <bits/stdc++.h>
using namespace std;

void push_item(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void dijkstra(vector<pair<int, int>> adj[], int size, int source) {
    //traversing graph
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j].first << "," << adj[i][j].second << " ";
        cout << '\n';
    }
    cout << '\n';

    //dj starts😎
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(size, INT_MAX);
    dis[source] = 0;
    pq.push(make_pair(0, source));
    while ( !pq.empty() ) {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int> >::iterator it;
        for ( it = adj[prev].begin() ; it != adj[prev].end() ; it++) {
            int next = it->first;
            int nextDist = it->second;
            if ( dis[next] > dis[prev] + nextDist) {
                dis[next] = dis[prev] + nextDist;
                pq.push(make_pair(dis[next], next));
            }
        }

    }

    cout << "The shortest distances of all nodes from source " << source << " are: \n";
    for (int i = 0 ; i < size ; i++) cout << dis[i] << " ";
    cout << "\n";
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int V = 5; //v is no. of vertices
    vector<pair<int, int>> adj[V];
    push_item(adj, 0, 1, 2);
    push_item(adj, 0, 2, 1);
    push_item(adj, 1, 2, 3);
    push_item(adj, 1, 3, 4);
    push_item(adj, 2, 3, 6);
    push_item(adj, 2, 4, 5);
    push_item(adj, 3, 4, 8);

    int source = 1;

    dijkstra(adj, V, source);

//you can write dijkstra's in main function to avoid complications

    // for (auto x : adj) {
    //     for (auto y : x)
    //         cout << y.first << "," << y.second << " ";
    //     cout << '\n';
    // }

    //priority_queue<pair<int, int>> pq; max heap syntax
    //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //min heap syntax
    //priority_queue<int , vector<int>, greater<int>> p; ....simple code
    //vector<int> dis(V + 1, INT_MAX);

    /*
    If you pass arr[], it is same in function..but cannot use for-each loop
    If you pass vector, add &....if you want original to modify..adv..you can use for-each
    */


    /*graph
                     4
                 1 ----- 3
                /|      /|
             2 / |     / |
              /  |    /  |
              0  |3  /   |8
              \  |  / 6  |
             1 \ | /     |
                \|/      |
                 2-------4
                     5
      
    */
    return 0;
}

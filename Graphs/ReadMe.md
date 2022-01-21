GRAPHS TOPICS:

* Graph Creation (Adjacency List Implementation)
* Creating a Directed/Undirected Graph
* Passing Adj-List as Argument and its Traversal in another Function
* Iterative BFS
* DFS
* BFS Disconnected Graph Components (No. of Islands)
* Cycle Detection in Undirected Graph
* Cycle Detection in Directed graph
* Kahn's Algo (Toplogical Sort- BFS - Traversal)
* Shortest Path in a DAG (Use Topological Sort Idea)
* Dijkstra's Algo
* Bellman Ford Algo
* Prim's Algo - MST
* Clone a Graph
* When to use which Algo??



if there is an unweighted graph..cyclic/ascyclic/directed/undirected doesn't matter
i say find shortest path between this to this...
use BFS

if weighted...
then comes DIJKSTRA'S ALGO..
if you have +ve weighted graph..cyclic/ascyclic/directed/undirected doesn't matter...use this
but doesn't work with negative-weights and negative-cycles

if graph is +ve weighted, directed, acyclic to find shortest path..we can do better than dijkstra's
use TOPOLOGICAL SORT..this also doesn't work with -ve weights


now, what to do if the graph has -ve weights and
 
directed and acyclic..we use BELLMAN FORD ALGO

undirected(also a form of cyclic)..graph cannot be solved,the Algo will detect -ve weight cycle,i.e.,-ve weight b/w two,
as it will be moving back and forth on that -ve weight..and it will be infinite loop

directed n cyclic...Algo may or may not work..
Will work....if the cycle weight sum is not -ve
if -ve..then doesn't work,i.e.,graph cannot be solved..detects the -ve weight cycle

Now, how do we check for -ve weight cycle..
after n-1 times..
relax all edges once more..if value changes..you know there is -ve weight-cycle


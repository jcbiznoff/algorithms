/*
 * Mimimum Spanning Tree: Graph in Tree out, sum of edge weight is minimum
 *  Prim: select the next smallest edge (greedy way)
 *      pseudo implementation: simple - start from zero nodes, add node A to my tree, find edge connecting node A, select min weight edge a, continue until all vertex in my tree
 *      cost: O(mn)
 *  Kruskal: sort edges by min weight, add vertices connecting edge
 *      pseudo impl: sort edges by weight put them in a queue, select edge a, are vertex A and A' in same component? if not add to my tree and merge two components, repeat until no more edges left
 *
 *
 *Shortest Path:Graph, start, end in, label out. (to get the path, use distance[t], the backward pointer from t to s)
    Dijkstra's: like Prim, but evals weight + tot dist from start to next vertex a
        implementation: initialize distance with weight from start to adj vertex, set last to start, select vnext (unknown but minimizes dist[v]), for each edge (vnext,x) get dist[x] = min (dist[x], dist[vnext] + w(vnext,x)),
                        update last=vnext, add vnext to known set.
        analysis: O(n^2)
    All pair shortest (Floyd-Warshall): find vertex minimize longest distance to all other nodes
        implementation: adjacency matrix
        analysis: O(n^3)

Network flow algorithm: compute maximum flow from source to sink without capacity violation
*/


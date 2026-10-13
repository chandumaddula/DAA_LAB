
#include <iostream>
#include <algorithm>
using namespace std;

const int V = 5;

struct Edge
{
    int src, dest, weight;
};

// Sort edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Find the parent of a vertex
int findParent(int parent[], int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] =
           findParent(parent, parent[vertex]);
}

// Join two different sets
void unionSets(int parent[], int rank[],
               int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST(int graph[V][V])
{
    Edge edges[V * V];
    int edgeCount = 0;

    // Convert adjacency matrix into an edge array.
    // For an undirected graph, consider only i < j.
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by increasing weight
    sort(edges, edges + edgeCount, compare);

    int parent[V];
    int rank[V] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalWeight = 0;
    int edgesSelected = 0;

    cout << "Edge\tWeight\n";

    for (int i = 0;
         i < edgeCount && edgesSelected < V - 1;
         i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        // Select edge only if it does not create a cycle
        if (setU != setV)
        {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << '\n';

            totalWeight += edges[i].weight;

            unionSets(parent, rank, setU, setV);
            edgesSelected++;
        }
    }

    if (edgesSelected != V - 1)
    {
        cout << "Graph is disconnected; no MST exists.\n";
        return;
    }

    cout << "Total MST Weight: "
         << totalWeight << '\n';
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 3, 6, 0},
        {2, 0, 0, 4, 5},
        {3, 0, 0, 1, 7},
        {6, 4, 1, 0, 2},
        {0, 5, 7, 2, 0}
    };

    kruskalMST(graph);

    return 0;
}


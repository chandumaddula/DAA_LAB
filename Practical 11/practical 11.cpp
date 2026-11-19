#include <stdio.h>
#include <float.h>

#define N 4
#define INF DBL_MAX

void floydWarshall(double graph[N][N]) {
    double dist[N][N];
    int nxt[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
            nxt[i][j] = (i != j && graph[i][j] < INF) ? j : -1;
        }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] != INF && dist[k][j] != INF
                    && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    printf("Shortest distances:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                printf("INF   ");
            else
                printf("%.0f   ", dist[i][j]);
        }
        printf("\n");
    }

    int negCycle = 0;
    for (int i = 0; i < N; i++)
        if (dist[i][i] < 0) {
            negCycle = 1;
            break;
        }
    printf("\nHas negative cycle: %s\n", negCycle ? "Yes" : "No");

    int src = 0, dst = N - 1;
    if (nxt[src][dst] != -1) {
        int path[2 * N];
        int len = 0;
        int u = src;
        path[len++] = u;
        while (u != dst) {
            u = nxt[u][dst];
            path[len++] = u;
        }

        printf("\nPath %d -> %d: ", src, dst);
        for (int i = 0; i < len; i++) {
            if (i) printf(" -> ");
            printf("%d", path[i]);
        }
        printf(" (cost %.0f)\n", dist[src][dst]);
    } else {
        printf("\nNo path from %d to %d\n", src, dst);
    }
}

int main() {
    const double INF_IDX = 99999.0;
    double graph[N][N] = {
        {0,   3, INF_IDX, 7},
        {8,   0,   2, INF_IDX},
        {INF_IDX, INF_IDX, 0,   1},
        {2, INF_IDX, INF_IDX, 0}
    };

    floydWarshall(graph);
    return 0;
}

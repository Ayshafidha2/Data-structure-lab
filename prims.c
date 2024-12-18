#include <stdio.h>
#include <stdlib.h>

int main() {
    int u, v, n, i, j, ne = 1;
    int visited[10] = {0}, min, mincost = 0, cost[10][10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Number of nodes exceeds the limit of 10.\n");
        return 1;
    }

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Assign a large value for no connection
        }
    }

    visited[1] = 1; // Start with the first node
    printf("\n");

    while (ne < n) {
        min = 999;

        // Find the minimum cost edge
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("Edge %d: (%d, %d) cost: %d\n", ne++, u, v, min);
        mincost += min;
        visited[v] = 1;
        cost[u][v] = cost[v][u] = 999; // Mark the edge as used
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}


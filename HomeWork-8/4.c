#include <stdio.h>
#define INF 9999

int main() {
    int a[10][10], d[10], vis[10] = {0};
    int n, s, u, min;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i != j && a[i][j] == 0)
                a[i][j] = INF;
        }

    scanf("%d", &s);

    for (int i = 0; i < n; i++)
        d[i] = INF;

    d[s] = 0;

    for (int k = 0; k < n; k++) {
        min = INF;
        u = -1;

        for (int i = 0; i < n; i++)
            if (!vis[i] && d[i] < min) {
                min = d[i];
                u = i;
            }

        if (u == -1)
            break;

        vis[u] = 1;

        for (int v = 0; v < n; v++)
            if (!vis[v] && a[u][v] != INF &&
                d[u] + a[u][v] < d[v])
                d[v] = d[u] + a[u][v];
    }

    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", s, i, d[i]);

    return 0;
}
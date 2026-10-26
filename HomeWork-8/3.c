#include <stdio.h>

int a[10][10], vis[10], n;

void DFS(int v) {
    vis[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
        if (a[v][i] && !vis[i])
            DFS(i);
}

int main() {
    int e, u, v, s;

    scanf("%d%d", &n, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }

    scanf("%d", &s);
    DFS(s);

    return 0;
}
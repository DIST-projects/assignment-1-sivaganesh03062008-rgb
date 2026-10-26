#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[20];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

int main() {
    struct Edge e[100], t;
    int n, m, cost = 0, count = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (e[i].w > e[j].w) {
                t = e[i];
                e[i] = e[j];
                e[j] = t;
            }

    for (int i = 0; i < m && count < n - 1; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);

        if (a != b) {
            parent[a] = b;
            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            count++;
        }
    }

    if (count == n - 1)
        printf("Minimum cost = %d", cost);
    else
        printf("MST not possible");

    return 0;
}
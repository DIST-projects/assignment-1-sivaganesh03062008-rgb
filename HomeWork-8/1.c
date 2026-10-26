#include <stdio.h>
#define INF 9999

int main() {
    int a[10][10], vis[10] = {0};
    int n, i, j, u, v, min, cost = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    vis[0] = 1;

    for (int k = 0; k < n - 1; k++) {
        min = INF;
        u = v = -1;

        for (i = 0; i < n; i++)
            if (vis[i])
                for (j = 0; j < n; j++)
                    if (!vis[j] && a[i][j] != 0 &&
                        a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }

        if (v == -1) {
            printf("MST not possible");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);
        vis[v] = 1;
        cost += min;
    }

    printf("Minimum cost = %d", cost);
    return 0;
}
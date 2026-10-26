#include <stdio.h>

int main() {
    int a[20] = {10, 20, 30, 40, 50};
    int old = 5, size = 11;
    int h[11];

    for (int i = 0; i < size; i++)
        h[i] = -1;

    for (int i = 0; i < old; i++) {
        int j = a[i] % size;

        while (h[j] != -1)
            j = (j + 1) % size;

        h[j] = a[i];
    }

    for (int i = 0; i < size; i++)
        printf("%d : %d\n", i, h[i]);

    return 0;
}
#include <stdio.h>
#define SIZE 7

int h[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        h[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;

    for (int i = 0; i < SIZE; i++) {
        index = (key % SIZE + i * i) % SIZE;

        if (h[index] == -1) {
            h[index] = key;
            return;
        }
    }

    printf("Hash table full\n");
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, h[i]);
}

int main() {
    initialize();

    insert(22);
    insert(30);
    insert(50);

    display();
    return 0;
}
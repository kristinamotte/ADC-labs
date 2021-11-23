#include <stdio.h>
#include <stdlib.h>

#define N 3

int main() {
    int firstMatrix[N][N];
    int secondMatrix[N - 1][N - 1];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            firstMatrix[i][j] = rand() % 100;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            secondMatrix[i][j] = firstMatrix[i][i] + firstMatrix[j][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d\t", secondMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
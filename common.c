#define _CRT_SECURE_NO_WARNINGS
#ifndef COMMON_H
#define COMMON_H
#include<stdio.h>
#include <stdlib.h>

#define INF 2<<31 - 1

int** allocateMemory(int n)
{
    int** p = (int**)malloc(sizeof(int*) * n);
    for (int i = 0;i < n;i++)
        p[i] = (int*)calloc(n, sizeof(int));
    return p;
}
void releaseMemory(int** p, int n)
{
    for (int i = 0;i < n;i++)
        free(p[i]);
    free(p);
}
void input(int n, FILE* fp, int** adj)
{
    int v, u;
    for (int i = 1; i <= n; i++) {
        fscanf(fp, "%d", &v);
        while (fscanf(fp, "%d", &u) == 1) {
            adj[v][u] = 1;
            int c = fgetc(fp);
            if (c == '\n' || c == EOF) break;
        }
    }

    // 인접 행렬 출력
    /*
    printf("%d번째 그래프 인접행렬\n", graphIndex);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    printf("\n");*/

    return;
}

#endif
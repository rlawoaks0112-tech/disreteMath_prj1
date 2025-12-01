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
#endif


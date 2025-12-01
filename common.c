#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "common.h"

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

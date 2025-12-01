#define _CRT_SECURE_NO_WARNINGS
#ifndef COMMON_H
#define COMMON_H
#include<stdio.h>
#include <stdlib.h>

#define INF 1000000

int** allocateMemory(int n);
void releaseMemory(int** p, int n);
void input(int n, FILE* fp, int** adj);

#endif
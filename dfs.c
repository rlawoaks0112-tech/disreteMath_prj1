//깊이 우선 탐색, 스택 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

#define MAX 100

//여기부터 스택 구현
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;


static int is_empty() {  //공백 여부 검출 함수
    return (top == -1);
}

static int is_full() { //포화 검출 함수
    return (top == (MAX_STACK_SIZE - 1));
}

static void push(int item) { //스택 삽입 함수
    if (is_full()) {
        printf("스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

static int pop() { //스택 팝 함수
    if (is_empty()) {
        printf("스택 공백상태\n");
        exit(1);
    }
    else return stack[top--];
}

static int peek() { //스택 피크 함수
    if (is_empty()) {
        printf("스택 공백상태\n");
        exit(1);
    }
    else return stack[top];
}

//여기까지 스택 구현



//dfs 알고리즘 구현(스택 사용)
void dfs(int v, int n, int* visited, int** adj) {
    int w;

    //첫 방문이면 경로에 출력
    if (!visited[v]) {
        if (top == -1)
            printf("%d", v);
        else
            printf(" - %d", v);
    }

    visited[v] = 1; //방문에 저장
    push(v); //스택에 저장
    for (w = 1; w <= n; w++) {
        if (adj[v][w] && !visited[w]) {
            dfs(w, n, visited, adj);
        }
    }

    pop();
}
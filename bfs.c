#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

//여기부터 원형큐 구현
#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

static void init_queue(QueueType* q) { //큐 초기화 함수
    q->front = q->rear = 0;
}

static int is_empty(QueueType* q) { //공백 검출 함수
    return (q->front == q->rear);
}

static int is_full(QueueType* q) { //포화 검출 함수
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

static void enqueue(QueueType* q, int data) { //삽입함수
    if (is_full(q)) {
        printf("큐가 포화상태");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

static int dequeue(QueueType* q) { //삭제 함수
    if (is_empty(q)) {
        printf("큐가 공백상태");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

static int peek(QueueType* q) { //가장 앞 원소 읽음
    if (is_empty(q)) {
        printf("큐가 공백상태");
        exit(1);
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//여기까지 원형큐 구현


//bfs 구현
void bfs(int start, int n, int* visited, int** adj) {
    QueueType q; //원형큐 생성
    init_queue(&q); //원형큐 초기화

    visited[start] = 1;
    enqueue(&q, start); //시작 정점 넣고 시작
    printf("%d", start);
    while (!is_empty(&q)) {
        int v = dequeue(&q); //지금 정점 꺼내기

        for (int i = 1; i <= n;i++) {
            if (adj[v][i] && !(visited[i])) { //인접하고 미방문인 경우 조건 실행
                visited[i] = 1;
                enqueue(&q, i);
                printf(" - %d", i);
            }
        }
    }

}
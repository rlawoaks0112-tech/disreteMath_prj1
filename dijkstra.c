#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "common.h"

typedef struct {
    int dist;  //시작점(1)부터의 거리
    int prev;  //방문 이전 노드 저장
}Path; //노드별 정보 저장 구조체

int min_dist(Path path[], int visited[], int n) {
    //방문하지 않은 정점 중 시작점과의 거리가 가장 짧은 점 선택

    int min = INF;
    int min_index = -1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && path[i].dist < min) {
            min = path[i].dist;
            min_index = i;
        }
    }
    return min_index;
}

void print_path(int start, int target, Path* path) {
    if (start == target) {
        printf("1");
        return;
    }
    //오류 방지
    if (path[target].prev == -1) return;

    print_path(start, path[target].prev, path);
    printf(" - %d", target + 1);
    return;
}

void Dijkstra(int n, int* visited, int** adj, int** weight, Path* path) {

    for (int i = 0; i < n; i++) {
        int w = min_dist(path, visited, n);

        if (w == -1 || path[w].dist == INF) break;

        visited[w] = 1; //선택된 정점을 방문으로 확정

        //확정된 정점을 토대로 이 점을 거쳐 거리가 짧아지는 정점 갱신
        for (int j = 0; j < n; j++) {
            if (adj[w][j] != 0) {
                if (path[w].dist + weight[w][j] < path[j].dist) {
                    path[j].dist = path[w].dist + weight[w][j];
                    path[j].prev = w;
                }
            }
        }

    }
    for (int i = 1; i < n; i++) {
        printf("정점 [%d] : ", i + 1);
        print_path(0, i, path);
        printf(", 길이: %d\n", path[i].dist);
    }
}

int main_dijkstra() {

    FILE* fp;
    int v, u;
    int w;
    int n, graphIndex = 1;

    //여기부터 파일 읽기
    fp = fopen("input2.txt", "r");
    if (!fp) {
        printf("파일 열기 실패- input2\n");
        return 1;
    }

    while (fscanf(fp, "%d", &n) == 1) {

        int** weight = allocateMemory(n+1);
        int** adj = allocateMemory(n+1);
        int* visited = (int*)malloc(sizeof(int) * (n+1));
        Path* path = (Path*)malloc(sizeof(Path) * (n+1));

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0; //인접행렬 초기화
                weight[i][j] = 0; //가중치 행렬 초기화
            }
            path[i].dist = INF;
            path[i].prev = -1;
            visited[i] = 0;
        }

        path[0].dist = 0; //시작점과의 거리는 0

        // 그래프 정보 읽기(인접 행렬 생성)
        for (int i = 0; i < n; i++) {
            fscanf(fp, "%d", &v);   // 각 줄의 첫 번째는 정점 번호
            
            while (1) {

                char c = fgetc(fp);
                while (c == ' ')
                    c = fgetc(fp);

                if (c == '\n' || c == EOF) break;
                ungetc(c, fp);

                fscanf(fp, "%d", &u); // 인접 정점 번호 읽기


                c = fgetc(fp);
                while (c == ' ') 
                    c = fgetc(fp);
                
                if (c == '\n' || c == EOF) break;
                ungetc(c, fp);

                fscanf(fp, "%d", &w); // 가중치 읽기
                    

                adj[v - 1][u - 1] = 1;
                weight[v - 1][u - 1] = w;
                //printf("check1\n");
            }
        }
        //n번 그래프 입력 종료
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d ", adj[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d ", weight[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */

        printf("\n\ngraph %d : \n",graphIndex);
        Dijkstra(n, visited, adj, weight, path);
        graphIndex++;

        releaseMemory(weight, n);
        free(visited);
        releaseMemory(adj, n);
        free(path);
    }

    fclose(fp);


    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "common.h"
int main()
{
    FILE* fp;
    int n, graphIndex = 1;
    int* visited,** adj;

    //----------------------bfs,dfs------------------------
    
    //파일 경로
    fp = fopen("input1.txt", "r");
    if (!fp) {
        printf("파일 열기 실패 - input1\n");
        goto jumpToDijkstra;
    }
    printf("1. 그래프 탐방 수행 결과\n\n");
    while (fscanf(fp, "%d", &n) == 1) 
    {
        //그래프가 여러개일 수 있음; 숫자 안나올때까지 무한반복
        //행렬 초기화
        visited = (int*)calloc(n + 1, sizeof(int));
        adj = allocateMemory(n + 1);

        // 그래프 정보 읽기(인접 행렬 생성) 및 출력(확인용)
        int v, u;
        for (int i = 1; i <= n; i++) {
            fscanf(fp, "%d", &v);
            //printf("%d\n", v);
            while (1) {
                char c = fgetc(fp);
                while (c == ' ' || c == '\t') {
                    c = fgetc(fp);
                }
                if (c == '\n' || c == EOF) break;
                ungetc(c, fp);

                fscanf(fp, "%d", &u);
                adj[v][u] = 1;
            }
        }


        //함수 사용해서 dfs, bfs 계산
        printf("그래프 [%d]\n", graphIndex);
        printf("---------------------------- \n");
        printf("깊이 우선 탐색\n");
        dfs(1, n, visited, adj);

        memset(visited, 0, sizeof(int) * (n + 1)); // 방문 여부 초기화
        printf("\n너비 우선 탐색\n",graphIndex);
        bfs(1, n, visited, adj);
        printf("\n============================");
        printf("\n\n");
        graphIndex++;

        releaseMemory(adj, n + 1);
        free(visited);
    }
    fclose(fp);

    
    //----------------------dijkstra---------------------
jumpToDijkstra:
    printf("2. 최단 경로 구하기 수행 결과");
    main_dijkstra();

}

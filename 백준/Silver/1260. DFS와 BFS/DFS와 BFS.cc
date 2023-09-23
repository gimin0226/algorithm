#include <stdio.h>
#define MAX_VERTICES 1001
int DFS_V[MAX_VERTICES] = { 0, }; //DFS를 실행하면서 방문한 정점을 표시하기 위한 배열
int BFS_V[MAX_VERTICES] = { 0, }; //BFS를 실행하면서 방문한 정점을 표시하기 위한 
int graph[MAX_VERTICES][MAX_VERTICES] = { 0, };
int queue[MAX_VERTICES];
void dfs(int v, int vertices);
void bfs(int v, int vertices);
 
int main() {
    int vertices, edges, vertex, i, j;
    scanf("%d %d %d", &vertices, &edges, &vertex);
 
    while (edges--) {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
 
    dfs(vertex, vertices);
    printf("\n");
    bfs(vertex, vertices);
 
    return 0;
}
 
void dfs(int v, int vertices) {
    int w;
    DFS_V[v] = 1;
    printf("%d ", v);
    for (w = 1; w <= vertices; w++) {
        if (graph[v][w] == 1 && DFS_V[w] == 0) {
            dfs(w, vertices);
        }
    }
}
 
void bfs(int v, int vertices) {
    int w;
    int front, rear, pop;
    front = rear = 0;
    printf("%d ", v);
    BFS_V[v] = 1;
    queue[0] = v; rear++;
    while (front < rear) {
        pop = queue[front]; front++;
        for (w = 1; w <= vertices; w++) {
            if (graph[pop][w] == 1 && BFS_V[w] == 0) {
                printf("%d ", w);
                queue[rear] = w; rear++;
                BFS_V[w] = 1;
            }
        }
    }
}

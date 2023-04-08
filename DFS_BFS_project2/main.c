#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 25
#define MAX_STACK_SIZE (MAX_N * MAX_N)

int N, cnt;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

typedef struct {
    int x;
    int y;
} Point;

Point stack[MAX_STACK_SIZE];
int top = -1;

void push(int x, int y) {
    stack[++top].x = x;
    stack[top].y = y;
}

Point pop() {
    return stack[top--];
}

int is_empty() {
    return top == -1;
}

void dfs(int x, int y) {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    visited[x][y] = 1;
    cnt++;

    push(x, y);

    while (!is_empty()) {
        Point p = pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                cnt++;
                push(nx, ny);
            }
        }
    }
}

int main() 
{    
    clock_t st, et;
    double stt, ett;
    int ans[MAX_N * MAX_N] = { 0, };
    int ans_idx = 0;
    scanf("%d", &N);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[i][j] = rand() % 2;
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    //st = clock();
    stt = (double)clock() / CLOCKS_PER_SEC;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans[ans_idx++] = cnt;
            }
        }
    }

    printf("%d\n", ans_idx);

    for (int i = 0; i < ans_idx; i++) {
        printf("%d\n", ans[i]);
    }
    //et = clock();
    ett = (double)clock() / CLOCKS_PER_SEC;

    //printf("%d ms", et - st);
    printf("%lf \n", ett - stt);
    return 0;
}
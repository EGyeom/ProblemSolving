#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1500

typedef struct {
    int x, y;
} Point;

char map[MAX][MAX + 1];
int water_visited[MAX][MAX];
int swan_visited[MAX][MAX];
int R, C;

// 빠른 큐 구현
Point water_queue[MAX * MAX], swan_queue[MAX * MAX];
int water_front, water_rear, swan_front, swan_rear;
Point next_water_queue[MAX * MAX], next_swan_queue[MAX * MAX];
int next_water_front, next_water_rear, next_swan_front, next_swan_rear;

void init_queues() {
    water_front = water_rear = 0;
    swan_front = swan_rear = 0;
    next_water_front = next_water_rear = 0;
    next_swan_front = next_swan_rear = 0;
}

int main() {
    scanf("%d %d", &R, &C);
    
    Point swan1 = {-1, -1}, swan2 = {-1, -1};
    
    // 입력 받으면서 초기 물 위치 큐에 추가
    for (int i = 0; i < R; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'L') {
                if (swan1.x == -1) {
                    swan1.x = i;
                    swan1.y = j;
                } else {
                    swan2.x = i;
                    swan2.y = j;
                }
                map[i][j] = '.';
            }
            if (map[i][j] == '.') {
                water_queue[water_rear++] = (Point){i, j};
                water_visited[i][j] = 1;
            }
        }
    }
    
    // 첫 번째 백조에서 시작
    swan_queue[swan_rear++] = swan1;
    swan_visited[swan1.x][swan1.y] = 1;
    
    int days = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (1) {
        // 백조가 만날 수 있는지 확인
        while (swan_front < swan_rear) {
            Point current = swan_queue[swan_front++];
            int x = current.x, y = current.y;
            
            // 다른 백조를 만났는지 확인
            if (x == swan2.x && y == swan2.y) {
                printf("%d\n", days);
                return 0;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || swan_visited[nx][ny]) {
                    continue;
                }
                
                swan_visited[nx][ny] = 1;
                
                if (map[nx][ny] == 'X') {
                    // 얼음이면 다음 날 탐색
                    next_swan_queue[next_swan_rear++] = (Point){nx, ny};
                } else {
                    // 물이면 바로 탐색 계속
                    swan_queue[swan_rear++] = (Point){nx, ny};
                }
            }
        }
        
        // 얼음 녹이기
        while (water_front < water_rear) {
            Point current = water_queue[water_front++];
            int x = current.x, y = current.y;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || water_visited[nx][ny]) {
                    continue;
                }
                
                if (map[nx][ny] == 'X') {
                    map[nx][ny] = '.';
                    water_visited[nx][ny] = 1;
                    next_water_queue[next_water_rear++] = (Point){nx, ny};
                }
            }
        }
        
        // 다음 날을 위한 큐 복사 (메모리 카피 사용)
        if (next_swan_rear > 0) {
            memcpy(swan_queue, next_swan_queue, sizeof(Point) * next_swan_rear);
            swan_front = 0;
            swan_rear = next_swan_rear;
            next_swan_rear = 0;
        } else {
            swan_front = swan_rear = 0;
        }
        
        if (next_water_rear > 0) {
            memcpy(water_queue, next_water_queue, sizeof(Point) * next_water_rear);
            water_front = 0;
            water_rear = next_water_rear;
            next_water_rear = 0;
        } else {
            water_front = water_rear = 0;
        }
        
        days++;
    }
    
    return 0;
}

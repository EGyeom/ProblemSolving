#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전역 변수 선언
int N;                    // 수의 개수
int numbers[11];          // 수열 저장 (N <= 11)
int operators[4];         // 연산자 개수 [덧셈, 뺄셈, 곱셈, 나눗셈]
int maxResult = -1000000000; // 최댓값 초기화 (-10억)
int minResult = 1000000000;  // 최솟값 초기화 (10억)

// DFS 기반 백트래킹 함수
// current: 현재까지의 계산 결과
// index: 다음에 사용할 숫자의 인덱스
void dfs(int current, int index) {
    // 모든 연산자를 사용한 경우 (기저 조건)
    if (index == N) {
        // 최댓값, 최솟값 갱신
        if (current > maxResult) maxResult = current;
        if (current < minResult) minResult = current;
        return;
    }

    // 각 연산자에 대해 시도
    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) { // 사용 가능한 연산자가 남아있는지 확인
            operators[i]--; // 연산자 사용

            int nextValue;
            switch (i) {
            case 0: // 덧셈
                nextValue = current + numbers[index];
                dfs(nextValue, index + 1);
                break;
            case 1: // 뺄셈
                nextValue = current - numbers[index];
                dfs(nextValue, index + 1);
                break;
            case 2: // 곱셈
                nextValue = current * numbers[index];
                dfs(nextValue, index + 1);
                break;
            case 3: // 나눗셈
                // 음수 나눗셈 처리 (C++14 기준)
                if (current < 0) {
                    nextValue = -((-current) / numbers[index]);
                }
                else {
                    nextValue = current / numbers[index];
                }
                dfs(nextValue, index + 1);
                break;
            }

            operators[i]++; // 연산자 개수 복구 (백트래킹)
        }
    }
}

int main() {
    // 입력 처리
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &operators[i]);
    }

    // DFS 시작 (첫 번째 숫자를 current로, 두 번째 숫자부터 index 1로 시작)
    dfs(numbers[0], 1);

    // 결과 출력
    printf("%d\n%d\n", maxResult, minResult);
    return 0;
}

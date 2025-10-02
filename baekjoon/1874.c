#include <stdio.h>

#define SIZE 100000

char answer[SIZE * 2]; // +, - 기호를 저장할 배열
int stack[SIZE];
int top = -1;

int main() {
    int n, e, num = 1, idx = 0, chk = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &e);

        // 현재까지 넣은 숫자(num)가 목표 숫자(e)보다 작거나 같으면, 목표 숫자까지 push
        while (num <= e) {
            stack[++top] = num++;
            answer[idx++] = '+';
        }

        // 스택의 top이 목표 숫자와 같으면 pop
        if (stack[top] == e) {
            top--;
            answer[idx++] = '-';
        }
        else { // 스택의 top이 목표 숫자보다 크면 수열을 만들 수 없음
            chk = 0;
            break;
        }
    }

    if (chk == 0) {
        printf("NO\n");
    }
    else {
        for (int i = 0; i < idx; i++) {
            printf("%c\n", answer[i]);
        }
    }
    return 0;
}

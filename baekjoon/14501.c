#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int T[16] = {0}; // 상담에 필요한 일수
    int P[16] = {0}; // 상담 금액
    int dp[17] = {0}; // dp[i]: i일부터 얻을 수 있는 최대 이익
    
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }
    
    // 뒤에서부터 DP 계산
    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 <= N) { // 상담이 퇴사 전에 끝나는 경우
            // 현재 상담을 하는 경우 vs 안 하는 경우
            dp[i] = (dp[i + T[i]] + P[i] > dp[i + 1]) ? dp[i + T[i]] + P[i] : dp[i + 1];
        } else { // 상담이 퇴사 후까지 걸리는 경우
            dp[i] = dp[i + 1];
        }
    }
    
    printf("%d\n", dp[1]);
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dp[301][2];
// 0 - 1칸
// 1 - 2칸

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%d", &dp[1][0]);
    dp[1][1] = dp[1][0];
    for(int i= 2; i <= n; i++)
    {
        scanf("%d", &dp[i][0]);
        dp[i][1] = dp[i][0];
        dp[i][1] += dp[i-2][0] > dp[i-2][1] ? dp[i-2][0] : dp[i-2][1];
        dp[i][0] += dp[i-1][1];
    }
    for(int i= 1; i <= n; i++)
    {
        printf("%d ", dp[i][0]);
    }
    printf("\n");
    for(int i= 1; i <= n; i++)
    {
        printf("%d ", dp[i][1]);
    }
    printf("\n");
    printf("%d\n", dp[n][0] > dp[n][1] ? dp[n][0] : dp[n][1]);
}
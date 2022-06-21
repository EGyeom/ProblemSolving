#include <bits/stdc++.h>
using namespace std;

long long dp[1001][3];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =1; i <= n; i++)
    {
        scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }
    long long ret = min(dp[n][0], dp[n][1]);
    printf("%lld\n", min(ret,dp[n][2]));
}

/* int main()
{
    int n;
    scanf("%d", &n);
    for(int i =0; i < n ; i++)
    {
        for(int j =0; j < 3; j++)
        {
            scanf("%d", &dp[i][j]);
        }
    }
    
    for(int i =1; i < n ; i++)
    {
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][1], dp[i-1][0]);
        printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
    }
    long long  ret = min(dp[n-1][0],dp[n-1][1]);
    ret = min(ret, dp[n-1][2]);
    printf("%lld\n", ret);
} */
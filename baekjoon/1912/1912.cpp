#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
    int n;
    int ret = -INT_MAX;
    scanf("%d", &n);

    for(int i = 1; i<= n; i++)
    {
        scanf("%d", &dp[i]);
        dp[i] = max(dp[i-1] + dp[i], dp[i]);
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
}


/* int main()
{
    int n;
    scanf("%d", &n);
    int ans = -1000;
    for(int i = 1; i <= n ; i++)
    {
        scanf("%d", &dp[i]);
        dp[i] = dp[i] > dp[i-1] +dp[i] ? dp[i] : dp[i-1] + dp[i];
        ans = ans > dp[i] ? ans : dp[i];
    }
    printf("%d\n", ans);
} */

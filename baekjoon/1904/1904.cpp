#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main()
{
    int n;
    scanf("%d", &n);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 15746;
    }

    printf("%d\n", dp[n]);
}
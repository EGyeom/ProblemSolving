#include <bits/stdc++.h>
using namespace std;

long long dp[91][2];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =0; i <2; i++) dp[1][i] = i;

    for(int i =2; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    printf("%lld\n", dp[n][0] + dp[n][1]);
}
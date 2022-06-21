#include <bits/stdc++.h>
using namespace std;
int dp[501][501];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            scanf("%d",&dp[i][j]);
            if(j == 1)
            {
                dp[i][j] += dp[i-1][j];
            }
            else if( j == i)
            {
                dp[i][j] += dp[i-1][j-1];
            }
            else
            {
                dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int ret = dp[n][1];
    for(int i = 2; i <= n; i++)
    {
        if(ret < dp[n][i]) ret = dp[n][i];
    }
    printf("%d\n", ret);
}

/* int main()
{
    int n;
    scanf("%d", &n);
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            scanf("%d", &dp[i][j]);
        }
    }
    for(int i =1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
            {
                dp[i][j] += dp[i-1][j];
            }
            else if(j == i)
            {
                dp[i][j] += dp[i-1][j-1];
            }
            else
            {
                dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }

    int ret = dp[n-1][0];
    for(int i =1; i < n; i++)
    {
        ret = max(ret,dp[n-1][i]);
    }

    printf("%d\n", ret);
} */
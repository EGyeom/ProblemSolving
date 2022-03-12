#include <bits/stdc++.h>
using namespace std;

int dp[100001][2];

int main()
{
    int t;
    // freopen("input.txt", "rt", stdin);
    scanf("%d", &t);
    for(int i =0; i < t; i++)
    {
        int n;
        scanf("%d" , &n);
        for(int j =1; j <= n; j++)
        {
            scanf("%d", &dp[j][0]);
        }
        for(int j =1; j <= n; j++)
        {
            scanf("%d", &dp[j][1]);
        }

        for(int j = 2; j <= n; j++ )
        {
            for(int k = 0; k <=1; k++)
            {
                int maxVal = dp[j-1][1^k];
                maxVal = max(maxVal, dp[j-2][0]);
                maxVal = max(maxVal, dp[j-2][1]);
                dp[j][k] += maxVal;
            }
        }
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
}
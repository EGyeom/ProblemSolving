#include <bits/stdc++.h>
using namespace std;

int dp[201][201];

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i = 0 ; i <=n; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= k ; i++) // 자리수
    {
        dp[i][0] = 1; 
        for(int j = 1; j <=n; j++) // 숫자 값
        {
            for(int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= 1000000000;
            }
        }
    }
    printf("%d\n", dp[k][n]);
}
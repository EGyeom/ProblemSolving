/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


    int dp[101][100001] = {0,};
    int weights[101] = {0,};
    int values[101] = {0,};

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", weights+i, values+i);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(weights[i] <= j)
            {
                dp[i][j] = dp[i-1][j-weights[i]] + values[i];
            }

            dp[i][j] = dp[i][j] < dp[i-1][j] ? dp[i-1][j] : dp[i][j];
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}

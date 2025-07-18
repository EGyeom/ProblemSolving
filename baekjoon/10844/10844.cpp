#include <bits/stdc++.h>
using namespace std;

int dp[101][10];

int main()
{
    int n ;
    scanf("%d", &n);
    for(int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j+1];
            }
            else if( j == 9)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
            dp[i][j] %= 1000000000;
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    int ret = 0;
    for(int i = 0; i < 10; i++)
    {
        ret += dp[n][i];
        ret %= 1000000000;
    }
    printf("%d\n",ret);
}

/* 
int main()
{
    int n ;
    scanf("%d" , &n);
    for(int i =1; i <= 9; i++ )
    {
        dp[1][i] = 1;
    }
    int sum = 0;
    for(int i =2; i <= n; i++)
    {
        for(int j =0; j <= 9 ; j++)
        {
            if(j == 0)  dp[i][j] = dp[i-1][j+1];
            else if(j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] = dp[i][j] % 1000000000;
        }
    }
    for(int i =0; i <= 9; i++)
    {
        sum += dp[n][i] ;
        sum %= 1000000000;
    }
    printf("%d\n", sum);
} */
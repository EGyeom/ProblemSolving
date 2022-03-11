#include <iostream>
#include <cstdio>

int dp[12];


int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int t=0;
    for(int j =4; j <= 10; i++)
    {
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    }
    scanf("%d", &t);
    for(int i =0; i < t; i++)
    {
        int n = 0;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}
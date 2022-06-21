#include <bits/stdc++.h>
using namespace std;

long long dp[101];

int main()
{
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 1;

    for(int i =0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(dp[temp]) {}
        else
        {
            for(int i = 3; i <= temp; i++)
            {
                dp[i] = dp[i-2] + dp[i-3];
            }
        }
        printf("%lld\n", dp[temp]);
    }
}
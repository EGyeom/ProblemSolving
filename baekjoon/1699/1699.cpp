#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int min = 100000000;
        for(int j = 1; j*j <= i; j++)
        {
            if(min > dp[i-(j*j)] + 1 ) min = dp[i-(j*j)] + 1;
        }
        dp[i] = min;
    }
    printf("%d\n", dp[n]);
}
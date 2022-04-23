#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i =1; i <= n; i++)
    {
        scanf("%d", &dp[i]);
    }
    for(int i =1 ; i <= n; i++)
    {
        int max = dp[i];
        for(int j = 1; j<=i/2; j++)
        {
            int temp = dp[i-j] + dp[j]; 
            max = max > temp ? max : temp;
        }
        dp[i] = max;
    }
    printf("%d\n", dp[n]);
}
#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main()
{
    int n;
    dp[1] = 1;
    dp[2] = 2;
    scanf("%d", &n);
    for(int i =3; i <= n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 10007;
    }

    printf("%d\n", dp[n]);
    return 0;
}
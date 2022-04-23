#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<int> arr(n+1,0);
    vector<int> dp(n+1,0);

    for(int i =1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dp = arr;
    int max =dp[1];
    for(int i =2; i<= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j]+ arr[i])
                dp[i] = dp[j] + arr[i];
        }
        if(max < dp[i]) max = dp[i];
    }
    printf("%d\n", max);
}
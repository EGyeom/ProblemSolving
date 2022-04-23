#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
    int n;
    scanf("%d", &n);
    int max = 0;

    for(int i =1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        dp[i] = 1;
        for(int j = 1; j <i; j++  )
        {
            if(arr[i] < arr[j] && dp[i] < dp[j] +1 )
            {
                dp[i] = dp[j] +1;
            }
        }
        max = max < dp[i] ? dp[i] : max;
    }
    printf("%d\n", max);
}
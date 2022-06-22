#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int arr[1001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i =0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }
    int ret = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = i-1; j >=0; j--)
        {
            if(arr[j] < arr[i] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] +1;
                if(ret < dp[i]) ret = dp[i];
            }
        }
    }
    printf("%d\n", ret);
}

/* int dp[1001];
int arr[1001];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dp[1] = 1;
    int max = 1;
    for(int i = 2; i <= n; i++)
    {
        int maxDP = 0;
        int maxIndex = 0;
        for(int j = 1 ; j <= i ; j++)
        {
            if(arr[j] < arr[i])
            {
                if(maxDP < dp[j])
                {
                    maxDP = dp[j];
                    maxIndex = j;
                }
            }
        }
        dp[i] = dp[maxIndex] +1;
        if( max < dp[i]) max = dp[i];
    }
    for(int i =1; i <=n ;i++)
    {
        printf("%d ", dp[i]);
    }
    printf("\n%d\n", max);
} */
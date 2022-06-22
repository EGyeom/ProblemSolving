/* #include <bits/stdc++.h>
using namespace std;

int dp[1001];
int arr[1001];
int main()
{
    int n;
    int max_index = 1;
    scanf("%d", &n);
    for(int i =1; i <= n ;i++)
    {
        dp[i] = 1;
        scanf("%d", &arr[i]);
        for(int j =1; j < i; j++)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[max_index] < dp[i]) max_index = i;
    }
    int maxValue = dp[max_index];
    for(int i = max_index; i <= n; i++)
    {
        for(int j = max_index; j <= i; j++)
        {
            if(arr[i] < arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if(maxValue < dp[i]) maxValue = dp[i];
    }
    printf("%d\n", maxValue);
} */

#include <bits/stdc++.h>
using namespace std;

int dp[1001][2];
int arr[1001];
int main()
{
    int n;
    scanf("%d", &n);

    for(int i =0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for(int i =1; i < n; i++)
    {
        for(int j = i-1; j >=0; j--)
        {
            if(arr[i] > arr[j] && dp[i][0] <= dp[j][0])
            {
                dp[i][0] = dp[j][0] + 1;
            }
        }
        for(int j = n-i; j < n; j++)
        {
            if(arr[n-i-1] > arr[j] && dp[n-i-1][1] <= dp[j][1])
            {
                dp[n-i-1][1] = dp[j][1] +1;
            }
        }
    }
    int ret = 0;
    for(int i =0; i < n; i++)
    {
        dp[i][0] += dp[i][1] -1;
        ret = max(dp[i][0], ret);
    }

    printf("%d\n", ret);
}

/* int dp[1001][2];
int arr[1001];
int main()
{
    int n;
    int max_index = 1;
    scanf("%d", &n);
    for(int i =1; i <= n ;i++)
    {
        dp[i][0] = 1;
        scanf("%d", &arr[i]);
        for(int j =1; j < i; j++)
        {
            if(arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1)
            {
                dp[i][0] = dp[j][0] + 1;
            }
        }
    }
    for(int i = n; i >= 1; i--)
    {
        dp[i][1] = 1;
        for(int j = n; j > i; j--)
        {
            if(arr[i] > arr[j] && dp[i][1] < dp[j][1] + 1)
            {
                dp[i][1] = dp[j][1] + 1;
            }
        }
    }
    int maxValue = 0;
    for(int i =1; i <=n; i++)
    {
        int temp = dp[i][0] + dp[i][1];
        if(maxValue < temp) maxValue = temp;
    }
    printf("%d\n", maxValue -1);
} */
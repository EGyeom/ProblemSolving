


#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int arr[10001];
int main()
{
    int n ;
    scanf("%d", &n);
    for(int i= 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        if(n == 1)
        {
            printf("%d\n", arr[i]);
            return 0;
        }
    }
    dp[1] = arr[1];
    int ret = dp[2] = dp[1] + arr[2];

    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i-2], dp[i-3]+arr[i-1]) + arr[i];
        dp[i] = max(dp[i], dp[i-1]);
        ret = max(ret,dp[i]);
    }
    printf("%d\n", ret);
}

/*
#define max(x,y) (x) > (y) ? x : y 
int dp[10001];
int arr[10001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i =1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        if(n==1)
        {
            printf("%d\n", arr[i]);
            return 0;
        } 
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i =3; i<=n; i++)
    {
        int maxVal= arr[i] + arr[i-1] + dp[i-3];
        maxVal =  max(maxVal,arr[i] + dp[i-2]);
        maxVal = max(maxVal, dp[i-1]);
        dp[i] = maxVal;
    }

    printf("%d\n", dp[n]);
} */
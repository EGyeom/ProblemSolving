#include <psinclude.h>

int dp[100001];

int recursive(int num)
{
    if(num == 1) return 0;
    else
    {
        if(num % 3 == 0)
        {
            if(dp[num] != 0) return dp[num];
            else return dp[num] = recursive(num/3) +1;
        }
        else if( num % 2 == 0)
        {
            if(dp[num] != 0) return dp[num];
            else return dp[num] = recursive(num/2) +1; 
        }
        else
        {
            if(dp[num] != 0) return dp[num];
            else return dp[num] = recursive(num-1) +1;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", recursive(n));
}